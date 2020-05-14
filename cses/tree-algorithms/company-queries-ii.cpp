#include <cpplib/stdinc.hpp>
#include <cpplib/graph/tree/lowest-common-ancestor.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1688
    desync();
    int n, q;
    cin >> n >> q;
    vvi adj(n+1);
    for(int i=2; i<=n; ++i){
        int p;
        cin >> p;
        adj[p].pb(i);
    }
    LCA lca(adj, 1);
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << lca.query(a, b) << endl;
    }
    return 0;
}
