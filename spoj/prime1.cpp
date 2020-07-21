#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/prime-number/gries-misra.hpp>

int32_t main(){
    desync();
    Sieve sv(MAX);
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        sv.segment(l, r);
        for(uint p : sv.segment_prime_numbers())
            cout << p << endl;
        cout << endl;
    }
    return 0;
}
