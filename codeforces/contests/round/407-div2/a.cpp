#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    int ans = 0, extra = 0;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        int d = x/k + (x%k != 0);
        ans += d/2;
        extra += d%2;
    }
    ans += extra/2 + (extra%2 != 0);
    cout << ans << endl;
    return 0;
}
