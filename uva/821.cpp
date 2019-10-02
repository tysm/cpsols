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
 * Extended Euclidian GCD.
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
 * Euclidian derivated LCM.
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
    int a, b, c = 0;
    while(cin >> a >> b, a+b){
        vector<vi> dis(101, vi(101, INF));
        while(a+b){
            dis[a][b] = 1;
            cin >> a >> b;
        }
        floyd(dis);
        int ans = 0, aux = 0;
        for(int i=1; i<=100; ++i){
            for(int j=1; j<=100; ++j){
                if(dis[i][j]==INF or i==j)
                    continue;
                ans += dis[i][j];
                aux++;
            }
        }
        cout << "Case " << ++c << ": average length between pages = ";
        cout << fixed << setprecision(3) << (double)ans/aux;
        cout << " clicks" << endl;
    }
    return 0;
}
