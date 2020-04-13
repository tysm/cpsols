#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1158
    desync();
    int n, x;
    cin >> n >> x;

    vi h(n);
    for(int &i:h)
        cin >> i;
    vi s(n);
    for(int &i:s)
        cin >> i;

    vvi dp(2, vi(x+1));
    for(int i=0; i<n; ++i){
        swap(dp[0], dp[1]);
        for(int j=1; j<=x; ++j){
            dp[0][j] = max(dp[1][j], dp[0][j-1]);
            if(j-h[i] >= 0)
                dp[0][j] = max(dp[0][j], dp[1][j-h[i]]+s[i]);
        }
    }
    cout << dp[0][x] << endl;
    return 0;
}
