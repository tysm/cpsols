#include <cpplib/stdinc.hpp>
#include <cpplib/adt/dsu.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    map<int, int> ma, mi;
    for(int i=0; i<n; ++i){
        ma[i] = i+1;
        mi[i] = i+1;
    }

    DSU dsu(n);
    for(int i=0; i<m; ++i){
        string s;
        cin >> s;
        if(s == "union"){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            if(dsu.same(u, v))
                continue;
            int fu = dsu.find(u), fv = dsu.find(v);

            int ma_u = ma[fu], mi_u = mi[fu], ma_v = ma[fv], mi_v = mi[fv];
            ma.erase(fu);
            mi.erase(fu);
            ma.erase(fv);
            mi.erase(fv);

            dsu.merge(u, v);
            int res = dsu.find(u);

            ma[res] = max(ma_u, ma_v);
            mi[res] = min(mi_u, mi_v);
        }
        else{
            int u;
            cin >> u;
            u--;
            int res = dsu.find(u);
            cout << mi[res] << ' ' << ma[res] << ' ' << dsu.size(res) << endl;
        }
    }
    return 0;
}
