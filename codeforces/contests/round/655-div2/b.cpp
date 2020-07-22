#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 1, l = n-1;
        for(int i=2; i*i<=n; ++i){
            if(n%i == 0 and (n/i)*(i-1) < l){
                ans = n/i;
                l = i;
            }
        }
        cout << ans << ' ' << n-ans << endl;
    }
    return 0;
}
