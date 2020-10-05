#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/euclid.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    int gl = 1;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        gl = gcd(k, lcm(x, gl));
    }
    cout << (gl == k? "Yes" : "No") << endl;
    return 0;
}
