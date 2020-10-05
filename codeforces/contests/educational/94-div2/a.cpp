#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans;
        for(int i=0; i<n; ++i)
            ans += s[n-1];
        cout << ans << endl;
    }
    return 0;
}
