#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for(int i=1; i<=n/2; ++i)
            ans += i*i;
        cout << ans*8 << endl;
    }
    return 0;
}
