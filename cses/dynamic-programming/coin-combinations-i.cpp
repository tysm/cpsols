#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1635
    desync();
    int n, x;
    cin >> n >> x;

    vi coins(n);
    for(int &i:coins)
        cin >> i;

    vi dp(x+1);
    dp[0] = 1;
    for(int i=1; i<=x; ++i){
        for(int c:coins){
            if(i-c < 0)
                continue;
            dp[i] = (dp[i] + dp[i-c])%M;
        }
    }
    cout << dp[x] << endl;
    return 0;
}
