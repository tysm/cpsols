#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << (gcd(a, b) == 1? a*b - a - b + 1 : -1) << endl;
    }
    return 0;
}
