#include <cpplib/stdinc.hpp>
#include <cpplib/adt/dsu.hpp>
#include <cpplib/graph/0-1-mst.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vvi adj(n);
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    DSU dsu = solve(adj);

    set<int> ans;
    for(int i=0; i<n; ++i)
        ans.ep(dsu.find(i));
    cout << ans.size() - 1 << endl;
    return 0;
}
