#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();

    int n[3];
    for(int i=0; i<3; ++i)
        cin >> n[i];

    vvi arr(3);
    for(int i=0; i<3; ++i){
        for(int j=0; j<n[i]; ++j){
            int x;
            cin >> x;
            arr[i].eb(x);
        }
        sort(rall(arr[i]));
    }

    int dp[n[0]+1][n[1]+1][n[2]+1] = {}, ans = 0;
    for(int i=0; i<=n[0]; ++i){
        for(int j=0; j<=n[1]; ++j){
            for(int k=0; k<=n[2]; ++k){
                if(i < n[0] and j < n[1])
                    dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k] + arr[0][i]*arr[1][j]);
                if(i < n[0] and k < n[2])
                    dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k] + arr[0][i]*arr[2][k]);
                if(j < n[1] and k < n[2])
                    dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k] + arr[1][j]*arr[2][k]);
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
