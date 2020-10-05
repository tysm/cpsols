#include <cpplib/stdinc.hpp>
#include <cpplib/graph/traversal/depth-first-search.hpp>

vi dfs(const int u, const vvi &adj, vi &vis, vi &par){
    vis[u] = -1;
    for(int v : adj[u]){
        if(!vis[v]){
            par[v] = u;
            vi aux = dfs(v, adj, vis, par);
            if(aux.size())
                return aux;
        }
        else if(vis[v] == -1){
            vi res;
            int cs = v, ce = u;
            res.pb(cs);
            while(ce != cs){
                res.pb(ce);
                ce = par[ce];
            }
            res.pb(cs);
            reverse(res.begin(), res.end());
            return res;
        }
    }
    vis[u] = 1;
    return vi();
}

int32_t main(){
    // https://cses.fi/problemset/task/1678
    desync();
    int n, m;
    cin >> n >> m;
    vvi adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    vi vis(n+1), par(n+1, -1), ans;
    for(int i=1; i<=n and ans.empty(); ++i){
        if(vis[i])
            continue;
        ans = dfs(i, adj, vis, par);
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
