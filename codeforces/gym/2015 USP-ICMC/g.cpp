#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    string s;
    cin >> s;
    bool neg = false;
    for(int i=0; i<s.size(); ++i){
        if(s[i] == '(' or s[i] == ')')
            continue;
        if(s[i] == '[' or s[i] == ']'){
            neg = !neg;
            if(s[i] == '[')
                s[i] = '(';
            else
                s[i] = ')';
        }
        else if(neg){
            if(s[i] >= 'a' and s[i] <= 'z')
                s[i] = 'A' + (s[i] - 'a');
            else if(s[i] >= 'A' and s[i] <= 'Z')
                s[i] = 'a' + (s[i] - 'A');
            else if(s[i] == '*')
                s[i] = '+';
            else
                s[i] = '*';
        }
    }
    cout << s << endl;
    return 0;
}
