#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vi psum(n);
        for(int i=0; i<n; ++i){
            psum[i] = (s[i] == '1');
            if(i)
                psum[i] += psum[i-1];
        }

        vi ans(n), on(n);
        for(int i=n-1; i>=0; --i){
            int sum = psum[n-1] - psum[i];
            ans[i] = sum;
            if(i + k <= n){
                int sum2 = psum[i+k-1]-psum[i] + (i + k < n? on[i+k] : 0);
                ans[i] = min(ans[i], sum2);
            }
            on[i] = ans[i] + (s[i] != '1');
            if(i < n-1)
                ans[i] = min(ans[i+1] + (s[i] != '0'), ans[i]);
        }
        cout << ans[0] << endl;
    }
    return 0;
}
