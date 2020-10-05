#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    reverse(all(arr));
    vvi dp(2, vi(k+1));
    dp[1][0] = 1;
    for(int i:arr){
        for(int j=0; j<=k; ++j){
            dp[0][j] = 0;
            if(j)
                dp[1][j] = mod(dp[1][j] + dp[1][j-1]);
        }
        for(int j=0; j<=k; ++j){
            int l = max((int)0, j-i);
            dp[0][j] = dp[1][j];
            if(l)
                dp[0][j]  = mod(dp[0][j] - dp[1][l-1]);
        }
        swap(dp[0], dp[1]);
    }
    cout << dp[1][k] << endl;
    return 0;
}
