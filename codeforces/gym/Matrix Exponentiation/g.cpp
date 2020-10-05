#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    matrix<mint, 10+3, 1> zn(0);
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        zn[i][0] = x;
    }
    zn[n][0] = 1; // 1
    zn[n+1][0] = n; // i
    zn[n+2][0] = n*n; // i*i

    vector<int> C(n);
    for(int i=n-1; i>=0; --i)
        cin >> C[i];

    int p, q, r;
    cin >> p >> q >> r;

    matrix<mint, 10+3> cf(0);

    for(int i=n-1; i>=0; --i)
        cf[n-1][i] = C[i]; // n += ci*(n-i)
    cf[n-1][n] = p; // n += p*1
    cf[n-1][n+1] = q; // n += q*i
    cf[n-1][n+2] = r; // n += r*i*i

    cf[n][n] = 1; // 1

    cf[n+1][n+1] = 1; // i
    cf[n+1][n] = 1; // i += 1 -> i+1

    cf[n+2][n+2] = 1; // i*i
    cf[n+2][n+1] = 2; // i*i += 2*i -> i*i + 2*i
    cf[n+2][n] = 1; // i*i + 2*i += 1 -> (i+1)*(i+1)

    for(int i=0; i<n-1; ++i)
        cf[i][i+1] = 1; // shift

    auto res = exp(cf, k)*zn;
    cout << res[0][0] << endl;
    return 0;
}
