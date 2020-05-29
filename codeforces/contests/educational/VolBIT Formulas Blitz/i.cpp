#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/binary-exponentiation.hpp>

int32_t main(){
    int n;
    cin >> n;
    int res = 2*4*3*bexp(4, n-3);
    if(n > 3)
        res += (n-3)*4*3*3*bexp(4, n-4);
    cout << res << endl;
    return 0;
}
