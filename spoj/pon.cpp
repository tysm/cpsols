#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/prime-number/miller-rabin.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(isprime(x))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}
