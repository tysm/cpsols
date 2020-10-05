#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

// enumerating blocks of k+1 rings
// we end up with the following formula:
// G(0) = if (M = N mod (K + 1)) == 0 then 0 else (2(M — 1) + 1)
// G(i) = 2G(i-1) + (2K + 1)

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    matrix<mint, 3, 1> g0(0);

    int m = n%(k+1);
    if(m)
        g0[0][0] = 2*(m-1) + 1; // g(0)
    g0[1][0] = k; // k
    g0[2][0] = 1; // 1

    matrix<mint, 3> cf(0);
    cf[0][0] = 2; // G(i) = 2*G(i-1)
    cf[0][1] = 2; // G(i) += 2*k
    cf[0][2] = 1; // G(i) += 1
    cf[1][1] = 1; // keep k
    cf[2][2] = 1; // keep 1

    cout << (exp(cf, n/(k+1))*g0)[0][0] << endl;
    return 0;
}

/* Another solution by deriving the formula:

#include <cpplib/adt/modular.hpp>
#include <cpplib/math/modprogression.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    mint ans = 0, c = 1;
    if(n >= k+1){
        ans += modsum_gp(2*k+1, 2, n/(k+1));
        c = exp((mint)2, n/(k+1));
    }
    if(n%(k+1)){
        int m = n%(k+1);
        ans += c*(2*(m-1)+1);
    }
    cout << ans << endl;
    return 0;
}*/
