#include <cpplib/stdinc.hpp>
#include <cpplib/graph/shortest-path/dijkstra.hpp>

int32_t main(){
    desync();
    int n, m, t, k, p;
    cin >> n >> m >> t >> k >> p;

    vb hasP(n+1);
    for(int i=0; i<p; ++i){
        int x;
        cin >> x;
        hasP[x] = true;
    }

    vvii adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c*60 + hasP[b]*k});
    }

    vi dis = dijkstra(1, adj, INF*INF);
    cout << (dis[n] <= t*60? dis[n] : -1) << endl;
    // adunda
    return 0;
}
