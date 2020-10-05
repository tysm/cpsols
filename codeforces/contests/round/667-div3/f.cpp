#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    string s, t;
    cin >> s >> t;

    vector<vvi> dp(n+1, vvi(k+1, vi(n+1, -INF)));
    dp[0][0][0] = 0;

    for(int i=0; i<n; ++i){
        for(int j=0; j<=k; ++j){
            for(int l=0; l<=n; ++l){
                if(dp[i][j][l] == -INF)
                    continue;
                int e0 = (s[i] == t[0]), e1 = (s[i] == t[1]), e01 = (t[0] == t[1]);

                dp[i+1][j][l+e0] = max(dp[i+1][j][l+e0], dp[i][j][l] + (e1? l : 0));
                if(j < k){
                    dp[i+1][j+1][l+1] = max(dp[i+1][j+1][l+1], dp[i][j][l] + (e01? l : 0));
                    dp[i+1][j+1][l+e01] = max(dp[i+1][j+1][l+e01], dp[i][j][l] + l);
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=k; ++i){
        for(int j=0; j<=n; ++j)
            ans = max(ans, dp[n][i][j]);
    }
    cout << ans << endl;
    return 0;
}
