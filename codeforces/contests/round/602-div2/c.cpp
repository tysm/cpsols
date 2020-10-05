#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        string t;
        for(int i=0; i<k-1; ++i)
            t += "()";
        int r = (s.size()-t.size())/2;
        for(int i=0; i<r; ++i)
            t += '(';
        for(int i=0; i<r; ++i)
            t += ')';

        vii ops;
        for(int i=0; i<n; ++i){
            if(s[i] == t[i])
                continue;
            int j = i+1;
            for(; j<n and s[j] != t[i]; ++j);
            ops.eb(i+1, j+1);
            reverse(s.begin()+i, s.begin()+j+1);
        }
        cout << ops.size() << endl;
        for(ii &i:ops)
            cout << i.ff << ' ' << i.ss << endl;
    }
    return 0;
}
