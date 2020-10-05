#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    // fi = fi-1 + fi+1
    // fi+1 = fi - fi-1
    desync();
    int x, y;
    cin >> x >> y;

    matrix<mint, 2, 1> base(0);
    base[0][0] = x;
    base[1][0] = y;

    matrix<mint, 2> cf(0);
    cf[1][1] = 1; // f(i) = f(i-1)
    cf[1][0] = -1; // f(i) -= f(i-2)
    cf[0][1] = 1; // shift

    int n;
    cin >> n;

    cout << (exp(cf, n-1)*base)[0][0] << endl;
    return 0;
}
