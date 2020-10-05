#include <cpplib/stdinc.hpp>
#include <cpplib/graph/shortest-path/dijkstra.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1195
    desync();
    int n, m;
    cin >> n >> m;
    vvii adj(n+1), adjinv(n+1);
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adjinv[b].pb({a, c});
    }
    vi from = dijkstra(1, adj, INF*INF), to = dijkstra(n, adjinv, INF*INF);
    int ans = from[n];
    for(int u=1; u<=n; ++u){
        for(ii vw:adj[u]){
            int v = vw.ff, w = vw.ss;
            ans = min(ans, from[u] + w/2 + to[v]);
        }
    }
    cout << ans << endl;
    return 0;
}
