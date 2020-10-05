#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    string s;
    cin >> s;

    int n = s.size(), ans = 0;
    for(int i=1; i<n; ++i){
        if(s[i] == 'K' and s[i-1] == 'V'){
            ans++;
            s[i] = s[i-1] = '_';
        }
    }
    for(int i=1; i<n; ++i){
        if(s[i] == s[i-1] and s[i] != '_'){
            ans++;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
