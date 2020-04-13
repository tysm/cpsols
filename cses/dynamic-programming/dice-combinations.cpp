#include <cpplib/stdinc.hpp>

vi dp(MAX);

int solve(int sum){
    if(dp[sum])
        return dp[sum];
    int ans = 0;
    for(int i=1; i<=6 and sum-i >= 0; ++i)
        ans = (ans + solve(sum-i))%M;
    return dp[sum] = ans;
}

int32_t main(){
    // https://cses.fi/problemset/task/1633
    desync();
    int n;
    cin >> n;
    dp[0] = 1;
    cout << solve(n) << endl;
    return 0;
}
