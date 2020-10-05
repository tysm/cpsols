#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    vvi dp(2, vi(m+1));
    for(int i=0; i<n; ++i){
        int w, v;
        cin >> w >> v;
        for(int j=1; j<=m; ++j){
            dp[0][j] = dp[1][j];
            if(j-w >= 0)
                dp[0][j] = max(dp[0][j], dp[1][j-w] + v);
        }
        swap(dp[0], dp[1]);
    }
    cout << dp[1][m] << endl;
    return 0;
}
