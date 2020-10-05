#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/divisor.hpp>
#include <cpplib/math/number-theory/prime-number/gries-misra.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1713/
    desync();
    Sieve sv(MAX);
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        cout << count_divisors(sv.factorization(x)) << endl;
    }
    return 0;
}
