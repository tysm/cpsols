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
 * Breadth First Search
 *
 * Note: in orther to retrieve the shortest
 * path we can store the predecessor of each
 * vertex when a successful relaxation occurs.
 *
 * Time Complexity: O(n + m).
 * Where n is the size of the graph and m is the quantity of edges.
 */
bool bfs(int s, vector<vi> &adj, int f, vi &sol, int id){
    if(sol[s])
        return false;
    sol[s] = id;

    queue<ii> q; q.push({s, f});
    while(!q.empty()){
        ii u = q.front(); q.pop();
        if(!u.ss)
            continue;

        for(int v : adj[u.ff]){
            if(sol[v] == id)
                continue;
            else if(sol[v])
                return false;

            sol[v] = id;
            q.push({v, u.ss-1});
        }
    }
    return true;
}

int32_t main(){
    desync();
    int t;
    scanf("%lld", &t);
    while(t--){
        int n, r, m;
        scanf("%lld %lld %lld", &n, &r, &m);
        vector<vi> adj(n);
        vi sol(n, 0);
        for(int i=0; i<r; ++i){
            int a, b;
            scanf("%lld %lld", &a, &b); a--; b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        bool valid = true;
        for(int i=1; i<=m; ++i){
            int k, s;
            scanf("%lld %lld", &k, &s); k--;
            if(valid)
                valid &= bfs(k, adj, s, sol, i);
        }
        for(int i:sol){
            if(!i)
                valid = false;
        }
        printf("%s\n", (valid? "Yes" : "No"));
    }
    return 0;
}
