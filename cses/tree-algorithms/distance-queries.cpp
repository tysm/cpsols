#include <cpplib/stdinc.hpp>
#include <cpplib/graph/tree/lowest-common-ancestor.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1135
    desync();
    int n, q;
    cin >> n >> q;
    vvi adj(n+1);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    LCA lca(adj, 1);
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << lca.distance(a, b) << endl;
    }
    return 0;
}
