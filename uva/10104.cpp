#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/euclid.hpp>

int32_t main(){
    desync();
    int a, b;
    while(cin >> a >> b){
        int g, x, y;
        tie(g, x, y) = extended_gcd(a, b);
        if(a == b and x > y)
            swap(x, y);
        cout << x << ' ' << y << ' ' << g << endl;
    }
    return 0;
}
