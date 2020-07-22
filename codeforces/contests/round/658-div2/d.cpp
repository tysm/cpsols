#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi coins;
        int acc = 0, cur = -1;
        for(int i=0; i<2*n; ++i){
            int x;
            cin >> x;
            if(x > cur and cur != -1){
                coins.eb(acc);
                acc = 0;
            }
            acc++;
            cur = max(cur, x);
        }
        coins.eb(acc);
        bool ans[n+1] = {};
        ans[0] = true;
        for(int c:coins){
            for(int i=n; i>=c; --i){
                if(ans[i-c])
                    ans[i] = true;
            }
        }
        cout << (ans[n]? "YES" : "NO") << endl;
    }
    return 0;
}
