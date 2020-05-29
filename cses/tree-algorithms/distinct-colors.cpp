#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>

int dfs(vvi &adj, vi &c, map<int, int> &pos, SegTree<RSumQ, int> &st, vi &t, vi &ntoi, int p, int u, int idx){
    if(pos.count(c[u]))
        st.update(pos[c[u]], -1);
    pos[c[u]] = idx;
    st.update(pos[c[u]], 1);
    ntoi[u] = idx;
    int r = idx;
    for(int v:adj[u]){
        if(v == p)
            continue;
        r = dfs(adj, c, pos, st, t, ntoi, u, v, r+1);
    }
    t[idx] = st.query(idx, r);
    return r;
}

int32_t main(){
    // https://cses.fi/problemset/task/1139
    desync();
    int n;
    cin >> n;
    vi c(n+1);
    for(int i=1; i<=n; ++i)
        cin >> c[i];
    vvi adj(n+1);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    map<int, int> pos;
    vi t(n), tr(n), ntoi(n+1);
    SegTree<RSumQ, int> st(n);
    dfs(adj, c, pos, st, t, ntoi, -1, 1, 0);
    for(int i=1; i<=n; ++i){
        if(i > 1)
            cout << ' ';
        cout << t[ntoi[i]];
    }
    cout << endl;
    return 0;
}
