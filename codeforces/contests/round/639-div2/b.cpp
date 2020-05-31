#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        while(n > 1){
            int lo = 1, hi = 1e9, res = 0;
            while(lo <= hi){
                int mid = (lo+hi)/2, sum = (((3+3*mid)*mid)/2)-mid;
                if(sum <= n){
                    lo = mid+1;
                    res = max(sum, res);
                }
                else
                    hi = mid-1;
            }
            ans += n/res;
            n %= res;
        }
        cout << ans << endl;
    }
    return 0;
}
