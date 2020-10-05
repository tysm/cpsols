#include <cpplib/stdinc.hpp>

void dfs(const int u, const vvi &adj, vb &vis, vi &ans){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v])
            dfs(v, adj, vis, ans);
        ans[u] = (ans[u] + ans[v])%M;
    }
}

int32_t main(){
    // https://cses.fi/problemset/task/1681
    desync();
    int n, m;
    cin >> n >> m;
    vvi req(n+1);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        req[b].pb(a);
    }
    vb vis(n+1); vis[1] = true;
    vi ans(n+1); ans[1] = 1;
    for(int i=2; i<=n; ++i){
        if(!vis[i])
            dfs(i, req, vis, ans);
    }
    cout << ans[n] << endl;
    return 0;
}
