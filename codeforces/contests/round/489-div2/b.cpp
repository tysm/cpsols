#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    set<int> d;
    for(int i=1; i*i<=y; ++i){
        if(y%i)
            continue;
        d.insert(i);
        d.insert(y/i);
    }
    int ans = 0;
    for(int a:d){
        int b = (x*y)/a;
        if(a < l or a > r or b < l or b > r or gcd(a, b) != x)
            continue;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
