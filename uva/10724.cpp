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
 * Note: this is the same algorithm as the
 * above, but it should be used when the
 * weights of the edges are real numbers.
 *
 * Time Complexity: O(exp(n, 3)).
 * Where n is the size of the graph.
 */
void floydd(vector<vd> &dis){
    int n = dis.size();
    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(dis[i][k] >= INF or dis[k][j] >= INF)
                    continue;
                if(dis[i][k] + dis[k][j] < dis[i][j] - EPS)
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
}

struct road{
    int ff;
    int ss;
    double c;
    double d;
    road(int ff, int ss, double d, double c) :
        ff(ff), ss(ss), d(d), c(c)
    {}
    bool operator<(const road &j) const{
        return tie(j.c, d, ff, ss) < tie(c, j.d, j.ff, j.ss);
    }
};

double edist(ii i, ii j){
    int dx = i.ff-j.ff, dy = i.ss-j.ss;
    return sqrtl(dx*dx+dy*dy);
}

int32_t main(){
    desync();
    int n, m;
    while(cin >> n >> m, n+m){
        vii nodes(n+1);
        for(int i=1; i<=n; ++i)
            cin >> nodes[i].ff >> nodes[i].ss;

        vector<vd> dis(n+1, vd(n+1, INF));
        for(int i=0; i<=n; ++i)
            dis[i][i] = 0;

        bool rexs[n+1][n+1];
        memset(rexs, false, sizeof(rexs));
        for(int i=0; i<m; ++i){
            int u, v;
            cin >> u >> v;
            dis[u][v] = dis[v][u] = edist(nodes[u], nodes[v]);
            rexs[u][v] = rexs[v][u] = true;
        }
        floydd(dis);

        set<road> r;
        for(int u=1; u<=n; ++u){
            for(int v=u+1; v<=n; ++v){
                if(rexs[u][v])
                    continue;
                double d = edist(nodes[u], nodes[v]), c = 0;
                for(int i=1; i<=n; ++i){
                    for(int j=i+1; j<=n; ++j){
                        double newd = min(
                            dis[i][u] + d + dis[v][j],
                            dis[i][v] + d + dis[u][j]
                        );
                        if(newd < dis[i][j] - EPS)
                            c += dis[i][j] - newd;
                    }
                }
                if(c > 1)
                    r.insert(road(u, v, d, c));
            }
        }
        if(r.size()==0)
            cout << "No road required" << endl;
        else
            cout << r.begin()->ff << ' ' << r.begin()->ss << endl;
    }
    return 0;
}
