#include <cpplib/stdinc.hpp>

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m = n-1, ans = 0;
        for(int i=0; i<32; ++i){
            if((m & 1<<i) != (n & 1<<i))
                ans++;
        }
        cout << ans << endl;
    }
}
