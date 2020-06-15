#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/modular-arithmetic/modular-multiplicative-inverse.hpp>

int32_t main(){
    desync();
    const int m = 998244353LL;
    vi fact(MAX);
    fact[0] = 1;
    for(int i=1; i<MAX; ++i)
        fact[i] = mod(i*fact[i-1], m);

    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i=1; i<=n; ++i){
        int d = n/i;
        if(d < k)
            continue;
        ans = mod(ans + mod(fact[d-1]*mmi(mod(fact[k-1]*fact[d-k], m), m), m), m);
    }
    cout << ans << endl;
    return 0;
}
