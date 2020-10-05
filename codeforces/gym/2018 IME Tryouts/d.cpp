#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int s;
        cin >> s;
        int l = 1, h = 2e9, ans = 0;
        while(l <= h){
            int m = (l+h)/2, sum = (1+m)*m/2;
            if(sum <= s){
                ans = m;
                l = m+1;
            }
            else
                h = m-1;
        }
        cout << ans << endl;
    }
    return 0;
}
