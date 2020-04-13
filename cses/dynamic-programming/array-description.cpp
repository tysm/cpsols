#include <cpplib/stdinc.hpp>

int n, m;
int v[int32_t(1e5)];
int dp[int32_t(1e5)][101];

int solve(int idx, int last){
    if(idx >= n)
        return 1;
    if(last != 0 and v[idx] != 0 and abs(last-v[idx]) > 1)
        return 0;
    if(dp[idx][last] != -1)
        return dp[idx][last];

    if(v[idx] != 0)
        return dp[idx][last] = solve(idx+1, v[idx]);

    int ans = 0;
    for(int i=1; i<=m; ++i){
        if(last != 0 and abs(last-i) > 1)
            continue;
        ans = (ans + solve(idx+1, i))%M;
    }
    return dp[idx][last] = ans;
}

int32_t main(){
    // https://cses.fi/problemset/task/1746
    desync();
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << endl;
    return 0;
}
