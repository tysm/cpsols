#include <cpplib/stdinc.hpp>

bool inv(string &s){
    for(int i=1; i<s.size(); ++i){
        if(s[i] >= 'a')
            return false;
    }
    return true;
}

int32_t main(){
    desync();
    string s;
    cin >> s;
    if(inv(s)){
        for(char c:s){
            if(c >= 'a')
                cout << (char)(c - 'a' + 'A');
            else
                cout << (char)(c - 'A' + 'a');
        }
    }
    else
        cout << s;
    cout << endl;
    return 0;
}
