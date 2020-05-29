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

inline int mod(int n, int m){
    int ret = n%m; 
    if(ret < 0) ret += m;
    return ret;
}

/**
 * Extended Euclidean GCD.
 *
 * Time Complexity: O(log(min(a, b))).
 */
pair<int, ii> gcd(int a, int b){
    if(a == 0) return {b, {0, 1}};
    pair<int, ii> res = gcd(b%a, a);
    int x1 = res.ss.ff, y1 = res.ss.ss;
    return {res.ff, {y1 - b/a*x1, x1}};
}

/**
 * Euclidean derivated LCM.
 *
 * Time Complexity: O(log(min(a, b))).
 */
int lcm(int a, int b){
    // same as a*b/gcd(a, b) but avoiding overflow.
    return a/gcd(a, b).ff*b;
}

/**
 * Floyd Warshall.
 *
 * Computes the shortest path for all pairs
 * in a weighted graph, given its adjacency
 * matrix.
 *
 * Note: here we assume the dis parameter
 * as the given adjacency matrix initially
 * and:
 * - dis[i][j] = INF if i and j aren't
 * adjacents for i,j in [0,n[ and i != j;
 * - dis[i][i] = 0 for i,j in [0,n[.
 *
 * Note: in orther to retrieve the shortest
 * path we can store the predecessor of each
 * vertex when a successful relaxation occurs.
 *
 * Time Complexity: O(exp(n, 3)).
 * Where n is the size of the graph.
 */
void floyd(vector<vi> &dis){
    int n = dis.size();
    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(dis[i][k] < INF and dis[k][j] < INF)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    for(int k=1; k<=t; ++k){
        int n, m;
        cin >> n >> m;
        vector<vi> adj(n, vi(n, INF));
        for(int j=0; j<m; ++j){
            int u, v;
            cin >> u >> v;
            adj[u][v] = adj[v][u] = 1;
        }
        for(int i=0; i<n; ++i)
            adj[i][i] = 0;
        floyd(adj);

        int s, d, ans = 0;
        cin >> s >> d;
        for(int i=0; i<n; ++i){
            if(adj[s][i] == INF or adj[i][d] == INF)
                continue;
            ans = max(ans, adj[s][i]+adj[i][d]);
        }
        cout << "Case " << k << ": " << ans << endl;
    }
    return 0;
}
