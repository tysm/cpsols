#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi arr(n);
        for(int &i:arr)
            cin >> i;
        reverse(all(arr));
        bool dp[n][2] = {};
        dp[0][0] = true;
        for(int i=1; i<n; ++i){
            if(arr[i] == 1){
                dp[i][0] = dp[i-1][1];
                dp[i][1] = dp[i-1][0];
            }
            else{
                dp[i][0] = true;
                dp[i][1] = false;
            }
        }
        if(dp[n-1][0])
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
    return 0;
}
