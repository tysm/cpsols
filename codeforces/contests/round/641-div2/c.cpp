#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/prime-number/gries-misra.hpp>
#include <cpplib/math/number-theory/binary-exponentiation.hpp>

int32_t main(){
    desync();
    Sieve sv(2e5);
    int n;
    cin >> n;
    vi arr(n);
    map<int, multiset<int> > aux;
    for(int &i:arr){
        cin >> i;
        auto factors = sv.factorization(i);
        for(auto f:factors)
            aux[f.ff].insert(f.ss);
    }
    int ans = 1;
    for(pair<int, multiset<int> > p:aux){
        if(p.ss.size() == n)
            p.ss.erase(p.ss.begin());
        if(p.ss.size() == n-1)
            ans *= bexp(p.ff, *p.ss.begin());
    }
    cout << ans << endl;
    return 0;
}
