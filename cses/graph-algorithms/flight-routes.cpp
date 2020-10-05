#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

pair<vi, vi> dijkstra(const int s, const vvii &adj, const int inf = INF){
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
    return {dis, par};
}

int32_t main(){
    // https://cses.fi/problemset/task/1196
    int n, m, k;
    cin >> n >> m >> k;
    vvii adj(n+1), adjinv(n+1);
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adjinv[b].pb({a, c});
    }

    pair<vi, vi> to = dijkstra(1, adj, INF*INF), from = dijkstra(n, adjinv, INF*INF);

    min_heap<pair<int, ii> > pq;
    for(int u=1; u<=n; ++u){
        for(ii p:adj[u]){
            int v = p.ff, w = p.ss;
            pq.push({to.ff[u] + w + from.ff[v], {u, v}});
        }
    }

    vi res;
    set<ii> vis;
    while(!pq.empty() and k){
        int ans = pq.top().ff, u = pq.top().ss.ff, v = pq.top().ss.ss;
        pq.pop();

        if(vis.count({u, v}))
            continue;

        vis.insert({u, v});
        while(to.ss[u] != -1){
            vis.insert({to.ss[u], u});
            u = to.ss[u];
        }
        while(from.ss[v] != -1){
            vis.insert({v, from.ss[v]});
            v = from.ss[v];
        }
        res.pb(ans); k--;
    }
    for(int i=0; i<res.size(); ++i){
        if(i)
            cout << ' ';
        cout << res[i];
    }
    cout << endl;
    return 0;
}
