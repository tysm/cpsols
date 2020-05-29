#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>
#include <cpplib/math/number-theory/prime-number/gries-misra.hpp>

vi dijkstra(int s, int need, vector<vector<pair<int, ii> > > &adj, const int inf = INF){
    vi dis(adj.size(), inf); dis[s] = 0; // distance from s to s is 0.
    min_heap<ii> pq; pq.push({dis[s], s});

    while(!pq.empty()){
        ii top = pq.top(); pq.pop();

        int d = top.ff, u = top.ss;
        if(d > dis[u])
            continue;

        for(pair<int, ii> p : adj[u]){
            int v = p.ff, x = p.ss.ff, w = p.ss.ss;
            if(x < need)
                continue;
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}

int32_t main(){
    desync();
    Sieve sv(5*MAX);
    vi primes(1, 2);
    for(int i=3; i<=5*MAX; ++i){
        if(sv.isprime(i))
            primes.pb(i);
    }

    int n, m, o, d;
    cin >> n >> m >> o >> d;

    vector<vector<pair<int, ii> > > adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b, x, c;
        cin >> a >> b >> x >> c;
        adj[a].pb({b, {x, c}});
    }
    vi ans = dijkstra(o, 1, adj, INF*INF);
    if(ans[d] != INF*INF){
        int ansx = 1, ansc = ans[d], lo = 0, hi = primes.size()-1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            ans = dijkstra(o, primes[mid], adj, INF*INF);
            if(ans[d] != INF*INF){
                ansx = primes[mid];
                ansc = ans[d];
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        cout << ansx << ' ' << ansx*ansc << endl;
    }
    else
        cout << 0 << ' ' << 0 << endl;
    return 0;
}
