#include <cpplib/stdinc.hpp>

int n;
vvi adj;
int dp[2][(int)1e5+1];

int solve(int u, int c, int p = -1){
    int &res = dp[c][u];
    if(res != -1)
        return res;
    res = 1;
    for(int v:adj[u]){
        if(v == p)
            continue;
        if(c)
            res = mod(res * solve(v, 0, u));
        else
            res = mod(res * mod(solve(v, 0, u) + solve(v, 1, u)));
    }
    return res;
}


int32_t main(){
    desync();
    cin >> n;
    adj.resize(n+1);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    memset(dp, -1, sizeof(dp));
    cout << mod(solve(1, 0) + solve(1, 1)) << endl;
    return 0;
}
