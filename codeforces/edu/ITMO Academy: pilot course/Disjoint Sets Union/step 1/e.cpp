#include <cpplib/stdinc.hpp>
#include <cpplib/adt/dsu.hpp>

map<int, set<int> > sts;

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vvi adj(n, vi(2));
    for(vi &v:adj){
        for(int &j:v){
            cin >> j;
            if(j > 0)
                j--;
        }
    }

    vii qr;
    for(int i=0; i<m; ++i){
        int u, h;
        cin >> u >> h;
        u--;
        h--;
        qr.eb(u, adj[u][h]);
        adj[u][h] = -1;
    }

    vi ans(n, -1);

    DSU dsu(n);
    for(int i=0; i<n; ++i)
        sts[i].ep(i);
    for(int i=0; i<n; ++i){
        for(int j:adj[i]){
            if(j == -1)
                continue;
            int u = i, v = j;
            if(dsu.size(v) > dsu.size(u))
                swap(u, v);

            int fu = dsu.find(u), fv = dsu.find(v);
            if(dsu.merge(fu, fv)){
                for(int k:sts[fv])
                    sts[fu].insert(k);
                sts.erase(fv);
            }
        }
    }

    for(int t=m-1; t>=0; --t){
        auto [u, v] = qr[t];
        if(dsu.same(v, 0))
            swap(u, v);
        int fu = dsu.find(u), su = dsu.size(u);
        int fv = dsu.find(v), sv = dsu.size(v);
        if(dsu.merge(fu, fv)){
            if(dsu.same(fu, 0)){
                for(int k:sts[fv])
                    ans[k] = t;
            }
            if(sv > su)
                swap(fu, fv);
            for(int k:sts[fv])
                sts[fu].insert(k);
            sts.erase(fv);
        }
    }

    for(int i:ans)
        cout << i << endl;
    return 0;
}
