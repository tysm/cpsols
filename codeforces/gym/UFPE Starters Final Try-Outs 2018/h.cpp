#include <cpplib/stdinc.hpp>

void dfs(vvi &adj, vi &vis, vb &cbh, vii &dp, int u){
    if(u == adj.size()-1){
        vis[u] = 2;
        dp[u] = {cbh[u], cbh[u]};
        // debug(u);
        // debug(dp[u].ff);
        // debug(dp[u].ss);
        return;
    }
    vis[u] = 1;

    ii res = {MAX, -1};
    for(int v:adj[u]){
        if(!vis[v])
            dfs(adj, vis, cbh, dp, v);
        else if(dp[v] == ii(MAX, -1))
            continue;
        if(vis[v] == 2){
            vis[u] = 2;
            res.ff = min(res.ff, cbh[u]+dp[v].ff);
            res.ss = max(res.ss, cbh[u]+dp[v].ss);
        }
    }
    dp[u] = res;
    // debug(u);
    // debug(dp[u].ff);
    // debug(dp[u].ss);
}

int32_t main(){
    desync();
    int n, c, m;
    cin >> n >> c >> m;

    vi vis(n+1);
    vb cbh(n+1);
    for(int i=0; i<c; ++i){
        int x;
        cin >> x;
        cbh[x] = true;
    }

    vii dp(n+1, {MAX, -1});
    vvi adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }

    dfs(adj, vis, cbh, dp, 1);

    cout << dp[1].ff << ' ' << dp[1].ss << endl;
    return 0;
}
