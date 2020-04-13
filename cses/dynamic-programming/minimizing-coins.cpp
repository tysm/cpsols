#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1634
    desync();
    int n, x;
    cin >> n >> x;

    vi coins(n);
    for(int &i:coins)
        cin >> i;

    vi dp(MAX, INF);
    dp[0] = 0;
    for(int i=1; i<=x; ++i){
        for(int c:coins){
            if(i-c < 0)
                continue;
            dp[i] = min(dp[i], 1+dp[i-c]);
        }
    }
    cout << (dp[x] == INF? -1 : dp[x]) << endl;
    return 0;
}
