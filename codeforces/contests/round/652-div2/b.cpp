#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i0 = -1, i1 = n;
        for(int i=0; i<n; ++i){
            if(s[i] == '0')
                i0 = i;
            else
                i1 = min(i1, i);
        }
        if(i0 < i1)
            cout << s << endl;
        else
            cout << s.substr(0, i1) + s.substr(i0) << endl;
    }
    return 0;
}
