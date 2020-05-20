#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/prime-number/gries-misra.hpp>

int32_t main(){
    desync();

    // Sieve sv(1e5);
    // vi primes;
    // for(int i=2; i<=1e5; ++i){
    //     if(sv.isprime(i))
    //         primes.pb(i);
    // }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vi arr(n+1);
        for(int i=1; i<=n; ++i)
            cin >> arr[i];

        vi dp(n+1, 1);
        for(int i=1; i<=n; ++i){
            for(int j=i+i; j<=n; j+=i){
                if(arr[j] > arr[i])
                    dp[j] = max(dp[j], dp[i]+1);
            }
        }

        int ans = 0;
        for(int i=1; i<=n; ++i)
            ans = max(ans, dp[i]);
        cout << ans << endl;
    }
    return 0;
}
