#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    bool ok = true;
    int cnt[2] = {};
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        if(x == 25)
            cnt[0]++;
        else if(x == 50){
            if(cnt[0])
                cnt[0]--;
            else{
                ok = false;
                break;
            }
            cnt[1]++;
        }
        else{
            if(cnt[0] and cnt[1]){
                cnt[0]--;
                cnt[1]--;
            }
            else if(cnt[0] >= 3)
                cnt[0] -= 3;
            else{
                ok = false;
                break;
            }
        }
    }
    cout << (ok? "YES" : "NO") << endl;
    return 0;
}
