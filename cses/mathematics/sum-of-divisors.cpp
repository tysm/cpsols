#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/modular-arithmetic/divisor.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1082
    desync();
    int n;
    cin >> n;
    cout << modrange_sum_divisors(n) << endl;
    return 0;
}
