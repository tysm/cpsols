#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        for(int i=1; i<=50; ++i){
            if((y-x)%i != 0)
                continue;
            vi ans;
            int cur = y;
            for(int j=0; j<n; ++j){
                if(cur > 0)
                    ans.eb(cur);
                else
                    break;
                cur -= i;
            }
            if(ans.back() > x)
                continue;
            if(ans.size() < n){
                cur = y+i;
                while(ans.size() < n){
                    ans.eb(cur);
                    cur += i;
                }
            }
            reverse(all(ans));
            cout << ans << endl;
            break;
        }
    }
    return 0;
}
