#include <cpplib/stdinc.hpp>

vb digits(int n){
    vb ans(10);
    while(n){
        ans[n%10] = true;
        n /= 10;
    }
    return ans;
}

int32_t main(){
    // https://cses.fi/problemset/task/1637
    desync();
    int n;
    cin >> n;
    vi dp(n+1, INF);
    dp[0] = 0;
    for(int i=1; i<=n; ++i){
        vb d = digits(i);
        for(int j=1; j<=9; ++j){
            if(!d[j] or i-j < 0)
                continue;
            dp[i] = min(dp[i], dp[i-j]+1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
