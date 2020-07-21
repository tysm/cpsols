#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/euclid.hpp>
#include <cpplib/math/number-theory/diophantus.hpp>

int32_t main(){
    desync();
    int a, b, c;
    cin >> a >> b >> c;
    int g = gcd(a, b);
    bool valid = !(c%g);
    if(valid){
        auto roots = diophantine(a, b, c);
        double lhs = -get<0>(roots), rhs = get<1>(roots);
        lhs *= g;
        lhs /= b;
        rhs *= g;
        rhs /= a;
        lhs = ceil(lhs);
        rhs = floor(rhs);
        if(rhs - lhs < 0)
            valid = false;
    }
    cout << (valid? "Yes" : "No") << endl;
    return 0;
}
