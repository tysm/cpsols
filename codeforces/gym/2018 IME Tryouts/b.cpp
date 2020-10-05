#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int acc = 0;
    char last = 0;
    string s;
    cin >> s;
    for(char c:s){
        if(c != last)
            acc = 0;
        acc++;
        if(acc == 3){
            cout << (c == 'C'? 'P' : 'T');
            acc = 0;
        }
        else
            cout << (c == 'C'? 'B' : 'D');
        last = c;
    }
    cout << endl;
    return 0;
}
