#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    matrix<mint, 2> a;
    a[0][0] = 0;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 1;
    if(n == 0)
        cout << 0 << endl;
    else
        cout << exp(a, n-1)[1][1] << endl;
    return 0;
}
