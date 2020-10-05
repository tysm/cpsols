#include <cpplib/stdinc.hpp>
#include <cpplib/graph/lca.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vvi adj(n);
    for(int i=1; i<n; ++i){
        int u, v;
        cin >> u >> v;
        adj[u-1].eb(v-1);
        adj[v-1].eb(u-1);
    }

    LCA lca(adj, 0);

    int q;
    cin >> q;
    while(q--){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        int l = lca.query(u, v);
        if(w >= lca.distance(u, l)){
            w -= lca.distance(u, l);
            if(w >= lca.distance(l, v))
                cout << v+1 << endl;
            else
                cout << lca.ancestor(v, lca.distance(l, v)-w)+1 << endl;
        }
        else
            cout << lca.ancestor(u, w)+1 << endl;
    }
    return 0;
}
