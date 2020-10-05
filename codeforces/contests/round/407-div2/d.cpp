#include <cpplib/stdinc.hpp>
#include <cpplib/math/combinatorics.hpp>

void dfs(int u, vvi &adj, vb &vis){
    vis[u] = true;
    for(int v:adj[u]){
        if(!vis[v])
            dfs(v, adj, vis);
    }
}

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vvi adj(n+1);
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    if(m < 2){
        cout << 0 << endl;
        return 0;
    }

    int acc = 0;
    vb vis(n+1);
    for(int i=1; i<=n; ++i){
        if(!vis[i]){
            dfs(i, adj, vis);
            acc++;
        }
    }
    if(acc == 1)
        cout << C(m, 2) << endl;
    else
        cout << 0 << endl;
    return 0;
}
