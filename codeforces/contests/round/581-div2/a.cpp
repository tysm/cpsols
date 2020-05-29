#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    string s;
    cin >> s;
    int ans = s.size()/2;
    if(s.size()%2 == 1){
        for(int i=1; i<s.size(); ++i){
            if(s[i] == '1'){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
