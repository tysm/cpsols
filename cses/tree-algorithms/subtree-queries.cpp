#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>

int dfs(vvi &adj, vi &values, vi &t, vi &tr, vi &ntoi, int p, int u, int idx){
    t[idx] = values[u];
    ntoi[u] = idx;
    int r = idx;
    for(int v:adj[u]){
        if(v == p)
            continue;
        r = dfs(adj, values, t, tr, ntoi, u, v, r+1);
    }
    return tr[idx] = r;
}

int32_t main(){
    // https://cses.fi/problemset/task/1137
    desync();
    int n, q;
    cin >> n >> q;
    vi v(n+1);
    for(int i=1; i<=n; ++i)
        cin >> v[i];
    vvi adj(n+1);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi t(n), tr(n), ntoi(n+1);
    dfs(adj, v, t, tr, ntoi, -1, 1, 0);
    SegTree<SegTreeKind::RSumQ, int> st(t);
    while(q--){
        int op, s, x;
        cin >> op >> s;
        if(op == 1){
            cin >> x;
            st.update(ntoi[s], x-st.query(ntoi[s]));
        }
        else
            cout << st.query(ntoi[s], tr[ntoi[s]]) << endl;
    }
    return 0;
}
