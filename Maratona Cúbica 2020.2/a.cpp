#include <cpplib/stdinc.hpp>
#include <cpplib/adt/modular.hpp>
#include <cpplib/math/gries-misra.hpp>

int32_t main(){
    Sieve sv(1e5);
    auto primes = sv.prime_numbers();

    desync();
    int t;
    cin >> t;

    while(t--){
        int l, r;
        cin >> l >> r;
        int n = r-l+1;

        vi arr(n, l);
        for(int i=0; i<n; ++i)
            arr[i] += i;

        vi cnt(n);
        for(int p:primes){
            for(int i = l - l%p; i<=r; i+=p){
                if(i - l < 0)
                    continue;
                int j = i-l;

                while(arr[j]%p == 0){
                    arr[j] /= p;
                    cnt[j]++;
                }
            }
        }
        for(int i=0; i<n; ++i)
            cnt[i] += (arr[i] != 1);

        vector<vector<mint> > dp(2, vector<mint>(32));
        for(int i=0; i<n; ++i){
            dp[1] = dp[0];

            int x = cnt[i];
            dp[1][x] += 1;
            for(int j=0; j<32; ++j){
                int v = j^x;
                dp[1][v] += dp[0][j];
            }
            swap(dp[0], dp[1]);
        }

        mint ans = 0;
        for(int i=1; i<32; ++i)
            ans += dp[0][i];
        cout << ans << ' ' << dp[0][0] << endl;
    }
    return 0;
}
