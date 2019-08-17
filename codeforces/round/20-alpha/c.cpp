#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

#define ff first
#define ss second
#define pb push_back

#define EPS 1e-9
#define MAX (int32_t(1e6)+1)
#define M (int32_t(1e9)+7)
const int INF = 1e18 + 1;

#define endl "\n"
#define debug(x) (cerr << #x << " = " << (x) << endl)
#define desync() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

inline int mod(int n, int m){
    int ret = n%m; 
    if(ret < 0) ret += m;
    return ret;
}

/**
 * Euclidian GCD.
 *
 * Time Complexity: O(log(min(a, b))).
 */
int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

/**
 * Euclidian derivated LCM.
 *
 * Time Complexity: O(log(min(a, b))).
 */
int lcm(int a, int b){
    // same as a*b/gcd(a, b) but avoiding overflow.
    return (a/gcd(a, b))*b;
}

/**
 * Binary Exponentiation.
 *
 * Time Complexity: O(log(e)).
 */
int bexp(int b, int e){
    int res = 1;
    while(e > 0){
        if(e & 1)
            res *= b;
        b *= b;
        e >>= 1;
    }
    return res;
}

/**
 * Binary Exponentiation with mod.
 *
 * Time Complexity: O(log(e)).
 */
int bexpm(int b, int e, int m = M){
    b %= m;
    int res = 1;
    while(e > 0){
        if(e & 1)
            res = (res*b)%m;
        b = (b*b)%m;
        e >>= 1;
    }
    return res;
}

/**
 * Dijkstra.
 * TODO validate.
 *
 * Note: in orther to retrieve the shortest path
 * we can store the predecessor of any vertex when
 * a successful relaxation occurs.
 *
 * Time Complexity: O(m*log(n)).
 * Where n is the size of the graph and m is the quantity of edges.
 */
vi dijkstra(int s, vector<vii> &adj){
    vi dis(adj.size(), INF); dis[s] = 0; // distance from s to s is 0.
    vi pre(adj.size(), -1);
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
                pre[v] = u;
                pq.push({dis[v], v});
            }
        }
    }
    return pre;
}

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    vector<vii> adj(n);
    for(int i=0; i<m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
    auto res = dijkstra(0, adj);
    if(res[n-1] == -1)
        cout << -1 << endl;
    else{
        vi path(1, n);
        for(int i = n-1; res[i] != -1; i = res[i])
            path.pb(res[i]+1);
        reverse(path.begin(), path.end());
        for(int i = 0; i < path.size(); ++i){
            if(i)
                cout << ' ';
            cout << path[i];
        }
        cout << endl;
    }
    return 0;
}
