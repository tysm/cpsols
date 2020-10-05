#include <cpplib/stdinc.hpp>

// sum[l...r] = r-l+1
// sum[r] - sum[l-1] = r-l+1
// sum[r] - r = sum[l-1]-l+1

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        map<int, int> cnt;

        int sum = 0, ans = 0;
        for(int r=0; r<n; ++r){
            cnt[sum-r+1]++;

            char c;
            cin >> c;

            int x = c-'0';
            sum += x;

            ans += cnt[sum-r];
        }
        cout << ans << endl;
    }
    return 0;
}
