#include <cpplib/stdinc.hpp>
#include <cpplib/graph/nodedist.hpp>

int32_t main(){
    desync();
    freopen("awesome.in", "r", stdin);

    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;

        vvi adj(n);
        for(int i=1; i<n; ++i){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].eb(v);
            adj[v].eb(u);
        }
        cout << solve(adj, n-1-l) - solve(adj, n-1-r-1) << endl;
    }
    return 0;
}
