#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/binary-exponentiation.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    if(n == 0)
        cout << 0 << endl;
    else
        cout << mod(mod(bexpm(2, k)*mod(mod(2*mod(n))-1))+1) << endl;
    return 0;
}
