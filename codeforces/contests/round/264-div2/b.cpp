#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int cur = 0, e = 0, ans = 0;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        e += cur-x;
        if(e < 0){
            ans += abs(e);
            e = 0;
        }
        cur = x;
    }
    cout << ans << endl;
    return 0;
}
