#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/binary-exponentiation.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1712
    desync();
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        cout << bexpm(a, bexpm(b, c, M-1)) << endl;
    }
    return 0;
}
