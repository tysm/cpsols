#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        vi cnt(40);
        int n;
        cin >> n;
        int ans = 0;
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;

            int msb = -1;
            for(int j=0; j<40; ++j){
                if(x & (1LL<<j)){
                    msb = j;
                }
            }
            ans += cnt[msb];
            cnt[msb]++;
        }
        cout << ans << endl;
    }
    return 0;
}
