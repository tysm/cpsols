#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    matrix<mint, 2, 1> base(0);
    base[0][0] = 1;

    matrix<mint, 2> cf(0);
    cf[0][0] = 3;
    cf[0][1] = 1;
    cf[1][0] = 1;
    cf[1][1] = 3;

    desync();
    int n;
    cin >> n;
    cout << (exp(cf, n)*base)[0][0] << endl;
    return 0;
}
