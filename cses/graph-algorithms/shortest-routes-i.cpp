#include <cpplib/stdinc.hpp>
#include <cpplib/graph/shortest-path/dijkstra.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1671
    int n, m;
    cin >> n >> m;
    vvii adj(n+1);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        // adj[b].pb({a, c});
    }
    vi dis = dijkstra(1, adj, INF*INF);
    for(int i=1; i<=n; ++i){
        if(i != 1)
            cout << ' ';
        cout << dis[i];
    }
    cout << endl;
    return 0;
}
