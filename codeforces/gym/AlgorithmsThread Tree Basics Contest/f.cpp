#include <cpplib/stdinc.hpp>
#include <cpplib/adt/segtree.hpp>
#include <cpplib/graph/lca.hpp>

int flatten(vvi &adj, vii &ntor, int u, int l, int p){
    int r = l;
    for(int v:adj[u]){
        if(v == p)
            continue;
        r = flatten(adj, ntor, v, r+1, u);
    }
    ntor[u] = {l, r};
    return r;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;

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

        vii ntor(n);
        flatten(adj, ntor, 0, 0, -1);

        SegTree<RSumQ, int> st(n);

        while(q--){
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            if(w){
                st.update(ntor[u].ff, w);
                st.update(ntor[v].ff, -w);
            }
            else{
                int l = lca.query(u, v);
                int resu = st.query(ntor[u].ff, ntor[u].ss);
                int resv = st.query(ntor[v].ff, ntor[v].ss);
                if(u == l)
                    cout << abs(resv) << endl;
                else
                    cout << abs(resu) << endl;
            }
        }
    }
    return 0;
}
