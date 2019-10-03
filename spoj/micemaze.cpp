#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

using ii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vii = vector<ii>;

#define ff first
#define ss second
#define pb push_back

#define EPS 1e-9
#define INF (int32_t(1e9)+1)
#define MAX (int32_t(1e6)+1)
#define M (int32_t(1e9)+7)

#define endl "\n"
#define debug(x) (cerr << #x << " = " << (x) << endl)
#define desync() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

/**
 * Dijkstra.
 *
 * Note: in orther to retrieve the shortest
 * path we can store the predecessor of each
 * vertex when a successful relaxation occurs.
 *
 * Time Complexity: O(m*log(n)).
 * Where n is the size of the graph and m is the quantity of edges.
 */
vi dijkstra(int s, vector<vii> &adj){
    vi dis(adj.size(), INF); dis[s] = 0; // distance from s to s is 0.
    priority_queue<ii, vii, greater<ii> > pq; pq.push({dis[s], s});

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
    desync();
    int n, e, t, m;
    cin >> n >> e >> t >> m;
    vector<vii> adj(n+1);
    for(int i=0; i<m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        adj[v].pb({u, c});
    }
    vi time = dijkstra(e, adj);
    int ans = 0;
    for(int i=1; i<=n; ++i){
        if(time[i] <= t)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
