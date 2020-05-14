#include <cpplib/stdinc.hpp>

ii dfs(int u, vb &vis, vvi &adj){
    ii ans = {0, u};
    vis[u] = true;
    for(int v:adj[u]){
        if(vis[v])
            continue;
        ii aux = dfs(v, vis, adj);
        aux.ff++;
        if(aux.ff > ans.ff)
            ans = aux;
    }
    return ans;
}

int32_t main(){
    // https://cses.fi/problemset/task/1131
    desync();
    int n;
    cin >> n;
    vvi adj(n+1);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vb vis(n+1);
    ii aux = dfs(1, vis, adj);
    vis = vb(n+1, false);
    cout << dfs(aux.ss, vis, adj).ff << endl;
    return 0;
}
