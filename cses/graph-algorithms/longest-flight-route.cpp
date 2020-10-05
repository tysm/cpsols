#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

vi dijkstra(const int s, const vvii &adj, const int inf = INF){
    vi par(adj.size(), -1), dis(adj.size(), inf); dis[s] = 0; // distance from s to s is 0.
    min_heap<ii> pq; pq.push({dis[s], s});

    while(!pq.empty()){
        ii top = pq.top(); pq.pop();

        int d = top.ff, u = top.ss;
        if(d > dis[u])
            continue;

        for(ii p : adj[u]){
            int v = p.ff, w = p.ss;
            if(dis[u] + w < dis[v]){
                par[v] = u;
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    return par;
}

int32_t main(){
    // https://cses.fi/problemset/task/1680
    desync();
    int n, m;
    cin >> n >> m;
    vvii adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb({b, -1});
    }
    vi par = dijkstra(1, adj, INF);
    if(par[n] == -1)
        cout << "IMPOSSIBLE" << endl;
    else{
        int i = n;
        vi ans;
        while(i != -1){
            ans.pb(i);
            i = par[i];
        }
        reverse(ans.begin(), ans.end());
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
