#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int a, b, q;
        cin >> a >> b >> q;
        int n = a*b;
        vi dp(n+1);
        for(int i=1; i<=n; ++i){
            dp[i] = dp[i-1];
            if((i%a)%b != (i%b)%a)
                dp[i]++;
        }
        for(int i=0; i<q; ++i){
            int l, r;
            cin >> l >> r;
            l--;
            cout << dp[n]*(r/n) + dp[r%n] - dp[n]*(l/n) - dp[l%n] << " \n"[i == q-1];
        }
    }
    return 0;
}
