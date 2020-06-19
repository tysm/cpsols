#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        for(int i=0; i<s.size(); ++i){
            if(i%2)
                continue;
            cout << s[i];
        }
        cout << s.back();
        cout << endl;
    }
    return 0;
}
