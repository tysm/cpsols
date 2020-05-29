#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/binary-exponentiation.hpp>

int32_t main(){
    desync();
    int n, k;
    while(cin >> n >> k, n+k){
        int res = 0, m = 1e7 + 7;
        res += bexpm(n, k, m);
        res = (res + bexpm(n, n, m))%m;
        res = (res + 2*bexpm(n-1, k, m))%m;
        res = (res + 2*bexpm(n-1, n-1, m))%m;
        cout << res << endl;
    }
    return 0;
}
