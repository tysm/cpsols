#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/linear-diophantine-equation.hpp>

int32_t main(){
    desync();
    int a, b, c;
    cin >> a >> b >> c;
    int g = gcd(a, b);
    bool valid = !(c%g);
    if(valid){
        auto roots = lde(a, b, c);
        double lhs = -roots.ff, rhs = roots.ss;
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
