#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << ' ' << lcm(a, b) << endl;
    }
    return 0;
}
