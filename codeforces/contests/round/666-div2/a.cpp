#include <cpplib/stdinc.hpp>

int32_t main(){

    desync();
    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        vi cnt(26);
        for(int i=0; i<n; ++i){
            string s;
            cin >> s;
            for(char c:s)
                cnt[c-'a']++;
        }
        bool ok = true;
        for(int i=0; i<26; ++i){
            if(cnt[i]%n)
                ok = false;
        }
        cout << (ok? "YES" : "NO") << endl;
    }
    return 0;
}
