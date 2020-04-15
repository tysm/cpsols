#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/binary-exponentiation.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1617
    desync();
    int n;
    cin >> n;
    cout << bexpm(2, n) << endl;
    return 0;
}
