#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int m;
    cin >> m;
    string cmd;
    cin >> cmd;
    cout << s[x-1];
    x--;
    for(char c:cmd){
        if(c == 'R')
            x++;
        else
            x--;
        cout << s[x];
    }
    cout << endl;
    return 0;
}
