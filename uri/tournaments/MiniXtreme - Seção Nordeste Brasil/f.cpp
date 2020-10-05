#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    while(cin >> n, n){
        int ans = 0;
        for(int i=0; i<n; ++i){
            int ci, vi;
            cin >> ci >> vi;
            ans += vi/2;
        }
        cout << ans/2 << endl;
    }
    cout << endl;
    return 0;
}
