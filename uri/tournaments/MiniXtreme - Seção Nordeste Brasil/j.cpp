#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        sort(all(s));
        if(s[0] == '0'){
            for(int i=1; i<s.size(); ++i){
                if(s[i] != '0'){
                    swap(s[i], s[0]);
                    break;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
