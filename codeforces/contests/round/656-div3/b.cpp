#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool cnt[n+1] = {};
        vi ans;
        for(int i=0; i<2*n; ++i){
            int x;
            cin >> x;
            if(!cnt[x])
                ans.eb(x);
            cnt[x] = true;
        }
        cout << ans << endl;
    }
    return 0;
}
