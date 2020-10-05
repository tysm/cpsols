#include <cpplib/stdinc.hpp>

vi cnt, link, add;

int ufind(int x){
    int v = link[x];
    while(v != link[v]){
        add[x] += add[v];
        v = link[v];
    }
    return link[x] = v;
}

bool same(int u, int v){
    return ufind(u) == ufind(v);
}

bool unionf(int u, int v){
    if(same(u, v))
        return false;
    u = ufind(u);
    v = ufind(v);
    if(cnt[v] > cnt[u])
        swap(u, v);
    cnt[u] += cnt[v];
    link[v] = u;
    add[v] -= add[u];
    return true;
}


int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    link.resize(n);
    iota(all(link), 0);
    cnt.resize(n, 1);

    add.resize(n);

    for(int i=0; i<m; ++i){
        string op;
        cin >> op;
        if(op == "join"){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            unionf(u, v);
        }
        else if(op == "add"){
            int u, x;
            cin >> u >> x;
            u--;
            int l = ufind(u);
            add[l] += x;
        }
        else{
            int u;
            cin >> u;
            u--;
            ufind(u);
            cout << add[u] + (u == link[u]? 0 : add[link[u]]) << endl;
        }
    }
    return 0;
}
