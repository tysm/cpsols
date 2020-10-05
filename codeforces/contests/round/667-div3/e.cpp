#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vi x(n);
        for(int &i:x)
            cin >> i;
        for(int i=0; i<n; ++i){
            int y;
            cin >> y;
        }
        sort(all(x));

        int ans = 0;
        vi res(n);
        for(int i=n-1; i>=0; --i){
            int &cur = res[i], v = x[i];
            int j = upper_bound(all(x), v+k) - x.begin();
            cur = j-i;
            if(j < n)
                ans = max(ans, cur + res[j]);
            ans = max(ans, cur);
            if(i < n-1)
                cur = max(cur, res[i+1]);
        }
        cout << ans << endl;
    }
    return 0;
}
