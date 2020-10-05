#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int ans = 0;
    map<int, int> msk;
    for(int i=0; i<n; ++i){
        string s;
        cin >> s;

        int m = 0;
        for(char c:s){
            int j = c-'a';
            m ^= 1<<j;
        }

        ans += msk[m];
        msk[m]++;
        for(int j=0; j<26; ++j)
            ans += msk[m ^ 1<<j];
    }
    cout << ans << endl;
    return 0;
}
