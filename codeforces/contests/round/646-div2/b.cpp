#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vi psum(n);
        for(int i=0; i<n; ++i){
            psum[i] = (s[i] == '1');
            if(i)
                psum[i] += psum[i-1];
        }
        int ans = INT_MAX;
        for(int i=0; i<n; ++i){
            int p0 = (i? psum[i-1] : 0);
            int p1 = (i? i-p0 : 0);
            int s0 = (i < n-1? psum[n-1] - psum[i] : 0);
            int s1 = (i < n-1? n-(i+1) - s0 : 0);
            ans = min({ans, p0+s1, p1+s0});
        }
        ans = min({ans, psum[n-1], n-psum[n-1]});
        cout << ans << endl;
    }
    return 0;
}
