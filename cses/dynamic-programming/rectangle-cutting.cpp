#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1744
    desync();
    int dp[501][501] = {};
    for(int i=1; i<501; ++i){
        for(int j=1; j<i; ++j){
            int ans = INF;
            for(int k=1; k<i; ++k)
                ans = min(ans, dp[i-k][j]+dp[k][j]);
            for(int k=1; k<j; ++k)
                ans = min(ans, dp[i][j-k]+dp[i][k]);
            dp[i][j] = dp[j][i] = ans+1;
        }
    }

    int a, b;
    cin >> a >> b;
    cout << dp[a][b] << endl;
    return 0;
}
