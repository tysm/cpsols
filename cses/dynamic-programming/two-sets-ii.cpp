#include <cpplib/stdinc.hpp>

int n, total;
int dp[501*250+1][501];

int solve(int sum, int i){
    if(i >= n)
        return 2*sum == total;
    if(dp[sum][i] != -1)
        return dp[sum][i];
    int ans = 0;
    ans = (ans + solve(sum, i+1))%M;
    ans = (ans + solve(sum+i, i+1))%M;
    return dp[sum][i] = ans;
}

int32_t main(){
    // https://cses.fi/problemset/task/1093
    desync();
    cin >> n;
    total = ((n+1)*n)/2;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1) << endl;
    return 0;
}
