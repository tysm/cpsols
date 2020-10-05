#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    int max_v = n*(1e3);
    vvi dp(2, vi(max_v+1, INF));
    dp[0][0] = dp[1][0] = 0;
    int ans = 0;
    for(int i=1; i<=n; ++i){
        int w, v;
        cin >> w >> v;
        for(int j=1; j<=max_v; ++j){
            dp[0][j] = dp[1][j];
            if(j >= v)
                dp[0][j] = min(dp[0][j], dp[1][j-v] + w);
            if(dp[0][j] <= m)
                ans = max(ans, j);
        }
        swap(dp[0], dp[1]);
    }
    cout << ans << endl;
    return 0;
}
