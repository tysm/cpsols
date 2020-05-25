#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int ans = n;
        for(int i=1; i*i<=n; ++i){
            if(n%i)
                continue;
            int x = i, y = n/i;
            if(x <= k)
                ans = min(ans, y);
            if(y <= k)
                ans = min(ans, x);
        }
        cout << ans << endl;
    }
    return 0;
}
