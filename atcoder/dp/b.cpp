#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    vi dp(n);
    for(int i=1; i<n; ++i){
        dp[i] = dp[i-1] + abs(arr[i] - arr[i-1]);
        for(int j=2; j<=k and i-j>=0; ++j)
            dp[i] = min(dp[i], dp[i-j] + abs(arr[i] - arr[i-j]));
    }
    cout << dp[n-1] << endl;
    return 0;
}
