#include <cpplib/stdinc.hpp>

vi link, cnt, dis;

int ufind(int u){
    if(u == link[u])
        return u;
    int l = link[u], res = ufind(l);
    dis[u] += dis[l];
    return link[u] = res;
}

bool same(int u, int v){
    return ufind(u) == ufind(v);
}

bool unionf(int u, int v){
    if(same(u, v))
        return false;
    int fu = ufind(u), fv = ufind(v);
    if(cnt[fv] > cnt[fu]){
        swap(u, v);
        swap(fu, fv);
    }
    link[fv] = fu;
    cnt[fu] += cnt[fv];
    dis[fv] = dis[v] + dis[u] + 1;
    return true;
}

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;

    link.resize(n);
    iota(all(link), 0);
    cnt.resize(n, 1);
    dis.resize(n);

    int sft = 0;
    while(q--){
        int op, u, v;
        cin >> op >> u >> v;
        u = (u+sft)%n;
        v = (v+sft)%n;
        if(!op)
            unionf(u, v);
        else{
            ufind(u);
            ufind(v);
            if((dis[u] + dis[v])%2 == 0){
                cout << "YES" << endl;
                sft++;
            }
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
