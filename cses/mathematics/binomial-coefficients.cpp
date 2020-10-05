#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/modular-arithmetic/modular-multiplicative-inverse.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1079
    desync();
    vi fac(MAX); fac[0] = 1;
    for(int i=1; i<MAX; ++i)
        fac[i] = (i*fac[i-1])%M;
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << (((fac[n]*mmi(fac[k]))%M)*mmi(fac[n-k]))%M << endl;
    }
    return 0;
}
