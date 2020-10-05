#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int sml = 0, fro = 0, n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0; i<n-1; ++i){
        if(s.substr(i, 2) == ":)" or s.substr(i, 2) == "(:")
            sml++;
        if(s.substr(i, 2) == ":(" or s.substr(i, 2) == "):")
            fro++;
    }
    if(sml == fro)
        cout << "BORED" << endl;
    else if(sml < fro)
        cout << "SAD" << endl;
    else
        cout << "HAPPY" << endl;
    return 0;
}
