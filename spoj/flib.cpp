#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    // G(0) = 0
    // G(1) = 2
    // G(2) = 2 + 13 == 7*G(1) - G(0) + 1
    // G(i) = 7*G(i-1) - G(i-2) + 1

    matrix<mint, 3, 1> var(0);
    var[1][0] = 2; // G(1)
    var[2][0] = 1; // 1

    matrix<mint, 3> cf(0);
    cf[1][1] = 7; // G(i) = 7*G(i-1)
    cf[1][0] = -1; // G(i) -= G(i-2)
    cf[1][2] = 1; // G(i) += 1
    cf[2][2] = 1; // 1 = 1
    cf[0][1] = 1; // shift

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << (exp(cf, n)*var)[0][0] << endl;
    }
    return 0;
}
