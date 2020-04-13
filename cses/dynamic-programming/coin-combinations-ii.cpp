#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1636
    desync();
    int n, x;
    cin >> n >> x;

    vi coins(n);
    for(int &i:coins)
        cin >> i;

    vi dp(x+1);
    dp[0] = 1;
    for(int c:coins){
        for(int i=1; i<=x; ++i){
            if(i-c < 0)
                continue;
            dp[i] = (dp[i] + dp[i-c])%M;
        }
    }
    cout << dp[x] << endl;
    return 0;
}
