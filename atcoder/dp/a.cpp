#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    vi dp(n);
    for(int i=1; i<n; ++i){
        dp[i] = dp[i-1] + abs(arr[i] - arr[i-1]);
        if(i >= 2)
            dp[i] = min(dp[i], dp[i-2] + abs(arr[i] - arr[i-2]));
    }
    cout << dp[n-1] << endl;
    return 0;
}
