#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vtt arr;
        for(int i=0; i<n; ++i){
            int l, r;
            cin >> l >> r;
            arr.eb(l, i, r);
        }
        sort(all(arr));

        int cur = 0;
        vi ans(n);
        for(auto [l, i, r] : arr){
            cur = max(cur, l);
            if(cur > r)
                continue;
            ans[i] = cur;
            cur++;
        }
        cout << ans << endl;
    }
    return 0;
}
