#include <cpplib/stdinc.hpp>

bool dfs(const int u, const vvi &adj, vi &vis, vi &ans){
    vis[u] = -1;
    bool valid = true;
    for(int v : adj[u]){
        if(!vis[v])
            valid &= dfs(v, adj, vis, ans);
        else if(vis[v] == -1)
            valid = false;
    }
    ans.pb(u);
    vis[u] = 1;
    return valid;
}

int32_t main(){
    // https://cses.fi/problemset/task/1679
    desync();
    int n, m;
    cin >> n >> m;
    vvi req(n+1);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        req[b].pb(a);
    }
    bool valid = true;
    vi vis(n+1), ans;
    for(int i=1; i<=n; ++i){
        if(vis[i])
            continue;
        valid &= dfs(i, req, vis, ans);
    }
    if(valid){
        for(int i=0; i<ans.size(); ++i){
            if(i)
                cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
