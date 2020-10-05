#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int x, y, k;
        cin >> x >> y >> k;

        int need = k-1 + k*y, ans = k;
        ans += need/(x-1);
        ans += (need%(x-1) > 0);

        cout << ans << endl;
    }
    return 0;
}
