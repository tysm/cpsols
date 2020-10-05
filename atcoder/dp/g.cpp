#include <cpplib/stdinc.hpp>

void dfs(vvi &adj, vi &ans, int u, int p = -1){
    ans[u] = 0;
    for(int v:adj[u]){
        if(v == p)
            continue;
        if(ans[v] == -1)
            dfs(adj, ans, v, u);
        ans[u] = max(ans[u], ans[v]+1);
    }
}

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    vvi adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    vi ans(n+1, -1);
    for(int i=1; i<=n; ++i){
        if(ans[i] == -1)
            dfs(adj, ans, i);
    }
    cout << *max_element(all(ans)) << endl;
    return 0;
}
