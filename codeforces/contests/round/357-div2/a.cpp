#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    bool ok = false;
    for(int i=0; i<n; ++i){
        string s;
        int bf, af;
        cin >> s >> bf >> af;
        if(af > bf and bf >= 2400)
            ok = true;
    }
    cout << (ok? "YES" : "NO") << endl;
    return 0;
}
