#include <cpplib/stdinc.hpp>

int n;
vvi adj;
int dp[21][1<<21];

int solve(int idx, int k){
    if(idx == n)
        return 1;
    int &res = dp[idx][k];
    if(res == -1){
        res = 0;
        for(int j:adj[idx]){
            int m = 1<<j;
            if(k & m)
                res = mod(res + solve(idx+1, k ^ m));
        }
    }
    return res;
}


int32_t main(){
    desync();
    cin >> n;
    adj.resize(n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            int a;
            cin >> a;
            if(a)
                adj[i].pb(j);
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, (1<<n)-1) << endl;
    return 0;
}
