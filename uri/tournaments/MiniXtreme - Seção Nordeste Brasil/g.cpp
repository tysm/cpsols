#include <cpplib/stdinc.hpp>

void dfs(vvi &adj, vb &vis, int u){
    vis[u] = true;
    for(int v:adj[u]){
        if(!vis[v])
            dfs(adj, vis, v);
    }
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vvi adj(n);
        for(int i=0; i<m; ++i){
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].eb(b);
        }
        bool ok = false;
        for(int i=0; i<n and !ok; ++i){
            vb vis(n);
            dfs(adj, vis, i);
            int cnt = 0;
            for(bool b:vis)
                cnt += b;
            if(cnt == n)
                ok = true;
        }
        cout << (ok? 'S' : 'N') << endl;
    }
    return 0;
}
