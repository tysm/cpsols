#include <cpplib/stdinc.hpp>
#include <cpplib/graph/traversal/depth-first-search.hpp>
#include <cpplib/graph/shortest-path/bellman-ford.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1197
    // desync();
    int n, m;
    cin >> n >> m;
    vvi adj(n+1);
    vvii adjw(n+1);
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(b);
        adjw[a].pb({b, c});
    }
    vb vis(n+1);
    for(int i=1; i<=n; ++i){
        if(vis[i])
            continue;
        dfs(i, adj, vis);
        vi ans = bellman(i, adjw, INF*INF).ff;
        if(ans.size()){
            cout << "YES" << endl;
            for(int j=0; j<ans.size(); ++j){
                if(j)
                    cout << ' ';
                cout << ans[j];
            }
            cout << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}