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

vector<pair<ii, ii> > dp;
vector<set<ii> > adj;


void merge(int u, int v, int w){
    if(dp[v].ff.ss == u){
        if(dp[v].ss.ff + w > dp[u].ff.ff){
            dp[u].ss = dp[u].ff;
            dp[u].ff = {dp[v].ss.ff + w, v};
        }
        else if(dp[v].ss.ff + w > dp[u].ss.ff)
            dp[u].ss = {dp[v].ss.ff + w, v};
    }
    else{
        if(dp[v].ff.ff + w > dp[u].ff.ff){
            dp[u].ss = dp[u].ff;
            dp[u].ff = {dp[v].ff.ff + w, v};
            //if(dp[v].ss.ss != u and dp[v].ss.ff + w > dp[u].ss.ff)
            //    dp[u].ss = {dp[v].ss.ff + w, v};
        }
        else if(dp[v].ff.ff + w > dp[u].ss.ff)
            dp[u].ss = {dp[v].ff.ff + w, v};
    }
}


int dfs(int p, int u){
    for(ii i:adj[u]){
        int v = i.ff, w = i.ss;
        if(v == p)
            continue;
        dfs(u, v);
        merge(u, v, w);
    }
    return dp[u].ff.ff;
}

void pdfs(int p, int u, int w){
    merge(u, p, w);
    while(!adj[u].empty()){
        ii i = *adj[u].begin();
        int v = i.ff, w = i.ss;
        adj[u].erase(adj[u].begin());
        adj[v].erase({u, w});
        pdfs(u, v, w);
    }
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        dp.clear();
        adj.clear();

        int n;
        cin >> n;
        adj.resize(n+1);
        dp.resize(n+1, {{0, -1}, {0, -1}});

        for(int i=0; i<n-1; ++i){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].insert({v, w});
            adj[v].insert({u, w});
        }

        for(int u=1; u<=n; ++u){
            if(u > 1)
                cout << ' ';
            cout << dfs(-1, u);

            while(!adj[u].empty()){
                ii i = *adj[u].begin();
                int v = i.ff, w = i.ss;
                adj[u].erase(adj[u].begin());
                adj[v].erase({u, w});
                pdfs(u, v, w);
            }
        }
        cout << endl;
    }
    return 0;
}
