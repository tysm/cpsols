#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    matrix<mint, 2> a;
    a[0][0] = 1 + 18;
    a[0][1] = 2 + 5;
    a[1][0] = 1 + 5;
    a[1][1] = 2 + 18;
    cout << exp(a, n)[0][0] << endl;
    return 0;
}
