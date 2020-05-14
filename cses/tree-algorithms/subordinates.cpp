#include <cpplib/stdinc.hpp>

int dp[MAX];

int dfs(const int u, const vvi &adj, vb &vis){
    int ans = 0;
    vis[u] = true;
    for(int v : adj[u]){
        if(vis[v])
            continue;
        ans += 1 + dfs(v, adj, vis);
    }
    return dp[u] = ans;
}

int32_t main(){
    // https://cses.fi/problemset/task/1674/
    desync();
    int n;
    cin >> n;

    vvi adj(n);
    for(int i=1; i<n; ++i){
        int x;
        cin >> x;
        adj[x-1].pb(i);
    }

    vb vis(n);
    for(int i=0; i<n; ++i){
        if(i)
            cout << ' ';
        cout << (vis[i]? dp[i] : dfs(i, adj, vis));
    }
    cout << endl;
    return 0;
}
