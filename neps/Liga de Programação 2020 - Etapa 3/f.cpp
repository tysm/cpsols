#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/modular-arithmetic/operation.hpp>

int32_t main(){
    desync();
    int m, n, k;
    cin >> m >> n >> k;

    m -= n;
    k--;

    vvi dp(2, vi(m+1));
    dp[1][0] = 1;
    while(n--){
        for(int i=0; i<=m; ++i){
            dp[0][i] = 0;
            if(i)
                dp[1][i] = (dp[1][i] + dp[1][i-1])%M;
        }
        for(int i=0; i<=m; ++i){
            int l = max((int)0, i-k);
            dp[0][i] = dp[1][i];
            if(l)
                dp[0][i] = mod(dp[0][i] - dp[1][l-1]);
        }
        swap(dp[0], dp[1]);
    }
    cout << dp[1][m] << endl;
    return 0;
}
