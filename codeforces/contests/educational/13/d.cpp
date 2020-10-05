#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>
#include <cpplib/adt/modular.hpp>

/*
#include <cpplib/math/number-theory/binary-exponentiation.hpp>
#include <cpplib/math/number-theory/modular-arithmetic/modular-multiplicative-inverse.hpp>

int spg(int a1, int q, int n){
    if(q == 1)
        return mod(a1*mod(n));
    return mod(mod(a1*mod(bexpm(q, n)-1))*mmi(q-1));
}

int32_t main(){
    desync();
    int a, b, n, x;
    cin >> a >> b >> n >> x;
    cout << mod(mod(x*bexpm(a, n)) + mod(b*spg(1, a, n))) << endl;
    return 0;
}
*/
