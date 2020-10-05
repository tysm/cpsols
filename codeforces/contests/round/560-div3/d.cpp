#include <cpplib/stdinc.hpp>
#include <cpplib/math/divisor.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi d(n);
        for(int &i:d)
            cin >> i;
        sort(all(d));
        int res = d[0]*d[n-1], ok = 1;
        for(int i=1; i<=n-i-1; ++i)
            ok &= (res == d[i]*d[n-i-1]);
        ok &= (count_divisors(res) == n + (res == 1? 0 : 2));
        cout << (ok? res : -1) << endl;
    }
    return 0;
}
