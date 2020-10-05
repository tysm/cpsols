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
    int n, m;
    cin >> n >> m;

    link.resize(n);
    iota(all(link), 0);
    cnt.resize(n, 1);
    dis.resize(n);

    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if(!unionf(u, v) and dis[u]%2 == dis[v]%2){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
