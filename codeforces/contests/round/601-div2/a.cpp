#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int d = abs(b-a), ans = 0;
        ans += d/5;
        d %= 5;
        ans += d/2;
        d %= 2;
        ans += d;
        cout << ans << endl;
    }
    return 0;
}
