#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

vi dijkstra(const int s, const vvii &adj, const int inf = INF){
    vi dis(adj.size(), inf); dis[s] = 0; // distance from s to s is 0.
    min_heap<ii> pq; pq.push({dis[s], s});

    while(!pq.empty()){
        ii top = pq.top(); pq.pop();

        int d = top.ff, u = top.ss;
        if(d > dis[u])
            continue;

        for(ii p : adj[u]){
            int v = p.ff, w = p.ss;
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}

int32_t main(){
    ifstream cin("jumping.in");
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vvii adj(n);
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            if(i+x < n)
                adj[i+x].eb(i, 1);
            if(i-x >= 0)
                adj[i-x].eb(i, 1);
        }
        vi ans = dijkstra(n-1, adj, LINF);
        for(int i=0; i<n; ++i)
            cout << (ans[i] == LINF? -1 : ans[i]) << endl;
    }
    return 0;
}
