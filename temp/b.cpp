#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/prime-number/gries-misra.hpp>

int32_t main(){
    desync();
    Sieve sv(MAX);

    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        if(x <= 2)
            cout << "NO" << endl;
        else{
            int s = sqrt(x);
            if(s*s == x and sv.isprime(s))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
