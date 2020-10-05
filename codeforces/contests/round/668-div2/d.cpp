#include <cpplib/stdinc.hpp>
#include <cpplib/graph/lca.hpp>
#include <cpplib/graph/treedmtr.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        a--;
        b--;

        vvi adj(n);
        for(int i=1; i<n; ++i){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].eb(v);
            adj[v].eb(u);
        }

        LCA lca(adj, 0);
        if(lca.distance(a, b) <= da or get<2>(tree_diameter(adj)) <= 2*da or db <= 2*da)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}
