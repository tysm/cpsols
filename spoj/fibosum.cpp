#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

int32_t main(){
    matrix<mint, 3, 1> base(0);
    base[1][0] = 1;

    matrix<mint, 3> cf(0);
    cf[1][1] = 1;
    cf[1][0] = 1;
    cf[2][2] = 1;
    cf[2][1] = 1;
    cf[0][1] = 1;

    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(!n)
            cout << (exp(cf, m)*base)[2][0] << endl;
        else
            cout << ((exp(cf, m) - exp(cf, n-1))*base)[2][0] << endl;
    }
    return 0;
}
