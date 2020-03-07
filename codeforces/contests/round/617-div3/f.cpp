#include <bits/stdc++.h>
using namespace std;

#define double long double
 
using ii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vb = vector<bool>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vvd = vector<vd>;
using vvb = vector<vb>;
using vvii = vector<vii>;
 
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
 
void dfs(int i, int u, vvi &adj, vvi &p){
    for(int v : adj[u]){
        if(v == i or p[i][v] != -1)
            continue;
        p[i][v] = u;
        dfs(i, v, adj, p);
    }
}
 
int32_t main(){
    int n;
    cin >> n;
 
    vii edgs;
    vvi adj(n+1);
    for(int i=0; i<n-1; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        edgs.pb({a, b});
    }
 
    vvi p(n+1, vi(n+1, -1));
    for(int i=1; i<=n; ++i)
        dfs(i, i, adj, p);
 
    int m;
    cin >> m;
 
    multiset<pair<int, ii> > mst;
    for(int i=0; i<m; ++i){
        int a, b, g;
        cin >> a >> b >> g;
        mst.insert({g, {a, b}});
    }
 
    vvi dp(n+1, vi(n+1, 0));
    for(auto i:mst){
        int a = i.ss.ff, b = i.ss.ss;
        while(a != b){
            int u = p[b][a];
            dp[a][u] = dp[u][a] = max(dp[a][u], i.ff);
            a = u;
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(!dp[i][j])
                dp[i][j] = 1e6;
        }
    }
    for(auto i:mst){
        int a = i.ss.ff, b = i.ss.ss, g = i.ff, ans = 1e6;
        while(a != b){
            int u = p[b][a];
            ans = min(ans, dp[a][u]);
            a = u;
        }
        if(ans > g){
            cout << -1 << endl;
            return 0;
        }
    }
 
    for(auto i:edgs)
        cout << dp[i.ff][i.ss] << ' ';
    cout << endl;
    return 0;
}
