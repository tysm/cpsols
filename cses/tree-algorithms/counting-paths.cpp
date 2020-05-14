#include <cpplib/stdinc.hpp>
#include <cpplib/graph/tree/lowest-common-ancestor.hpp>

int dfs(vvi &adj, vi &s, vi &e, vi &ans, int p, int u){
    int acc = s[u];
    for(int v:adj[u]){
        if(v == p)
            continue;
        acc += dfs(adj, s, e, ans, u, v);
    }
    ans[u] = acc - e[u];
    return acc - 2*e[u];
}

int32_t main(){
    // https://cses.fi/problemset/task/1136
    desync();
    int n, m;
    cin >> n >> m;
    vvi adj(n+1);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    LCA lca(adj, 1);
    vi s(n+1), e(n+1);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        s[a]++;
        s[b]++;
        e[lca.query(a, b)]++;
    }
    vi ans(n+1);
    dfs(adj, s, e, ans, -1, 1);
    for(int i=1; i<=n; ++i){
        if(i > 1)
            cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
