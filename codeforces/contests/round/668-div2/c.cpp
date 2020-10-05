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

        bool ok = true;
        int o = 0, z = 0;
        for(int i=0; i<k and ok; ++i){
            set<char> vis;
            for(int j=i; j<n; j+=k)
                vis.ep(s[j]);
            if(vis.count('1') and vis.count('0'))
                ok = false;
            else{
                if(vis.count('1'))
                    s[i] = '1';
                if(vis.count('0'))
                    s[i] = '0';
            }
            o += (s[i] == '1');
            z += (s[i] == '0');
            if(o > k/2 or z > k/2)
                ok = false;
        }
        cout << (ok? "YES" : "NO") << endl;
    }
    return 0;
}
