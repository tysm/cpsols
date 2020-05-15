#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vvi arr(n, vi(m));
        for(vi &i:arr){
            for(int &j:i)
                cin >> j;
        }
        int ans = INF*INF, a00 = arr[0][0];
        for(int x=0; x<n; ++x){
            for(int y=0; y<m; ++y){
                int base = arr[x][y] - x - y;
                if(base > a00)
                    continue;
                vvi dp(n, vi(m, INF*INF));
                dp[0][0] = a00-base;
                for(int i=0; i<n; ++i){
                    for(int j=0; j<m; ++j){
                        int cur = base + i + j;
                        if(cur > arr[i][j])
                            continue;
                        if(i)
                            dp[i][j] = min(dp[i][j], dp[i-1][j] + arr[i][j] - cur);
                        if(j)
                            dp[i][j] = min(dp[i][j], dp[i][j-1] + arr[i][j] - cur);
                    }
                }
                ans = min(ans, dp[n-1][m-1]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
