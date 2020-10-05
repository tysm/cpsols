#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    matrix<mint, 4> base(0);
    base[0][1] = base[1][0] = 1;
    base[0][2] = base[2][0] = 1;
    base[0][3] = base[3][0] = 1;
    base[1][2] = base[2][1] = 1;
    base[1][3] = base[3][1] = 1;
    base[2][3] = base[3][2] = 1;

    int n;
    cin >> n;
    cout << exp(base, n)[3][3] << endl;
    return 0;
}
