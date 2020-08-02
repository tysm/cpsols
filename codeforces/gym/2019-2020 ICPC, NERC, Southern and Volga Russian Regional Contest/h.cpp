#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int cnt[10] = {}, ans = 0;
        for(int i=0; i<10; ++i){
            cin >> cnt[i];
            if(cnt[i] < cnt[ans] or ans == 0 and cnt[i] == cnt[ans])
                ans = i;
        }
        if(ans == 0)
            cout << 1;
        for(int i=0; i<=cnt[ans]; ++i)
            cout << ans;
        cout << endl;
    }
    return 0;
}
