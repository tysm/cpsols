#include <cpplib/stdinc.hpp>

vi ans;

int dfs(int p, int u, vb &vis, vvi &adj){
    vis[u] = true;
    for(int v:adj[u]){
        if(v == p)
            continue;
        else if(vis[v]){
            ans.pb(v);
            ans.pb(u);
            return v;
        }
        else{
            int res = dfs(u, v, vis, adj);
            if(!res)
                continue;
            else if(res == -1)
                return -1;
            else{
                ans.pb(u);
                return res == u? -1 : res;
            }
        }
    }
    return 0;
}

int32_t main(){
    // https://cses.fi/problemset/task/1669
    desync();
    int n, m;
    cin >> n >> m;
    vvi adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vb vis(n+1, false);
    for(int i=1; i<=n; ++i){
        if(vis[i])
            continue;
        if(dfs(0, i, vis, adj))
            break;
    }
    if(ans.empty())
        cout << "IMPOSSIBLE" << endl;
    else{
        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); ++i){
            if(i)
                cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
