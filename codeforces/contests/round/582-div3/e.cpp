#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    cout << "YES" << endl;

    if(s[0] == t[0] and s[1] != t[1] and s[1] != s[0] and t[1] != t[0]){
        for(int i=0; i<n; ++i)
            cout << s[1] << t[1];
        for(int i=0; i<n; ++i)
            cout << s[0];
        cout << endl;
        return 0;
    }
    if(s[1] == t[1] and s[0] != t[0] and s[1] != s[0] and t[1] != t[0]){
        for(int i=0; i<n; ++i)
            cout << s[1];
        for(int i=0; i<n; ++i)
            cout << s[0] << t[0];
        cout << endl;
        return 0;
    }
    if(s[0] != s[1] and s[0] == t[1] and s[1] == t[0]){
        for(int i=0; i<n; ++i)
            cout << s[0];
        for(int i=0; i<n; ++i)
            cout << (s.find("a") == -1? 'a' : s.find("b") == -1? 'b' : 'c');
        for(int i=0; i<n; ++i)
            cout << s[1];
    }

    string ans;
    for(int i=0; i<3 and ans.size() == 0; ++i){
        for(int j=0; j<3 and ans.size() == 0; ++j){
            if(j == i)
                continue;
            for(int k=0; k<3 and ans.size() == 0; ++k){
                if(k == j or k == i)
                    continue;
                string p;
                p += 'a'+i;
                p += 'a'+j;
                p += 'a'+k;
                if(n > 1)
                    p += 'a'+i;
                if(p.find(s) != (size_t)-1)
                    continue;
                if(p.find(t) != (size_t)-1)
                    continue;
                ans = p.substr(0, 3);
            }
        }
    }
    for(int i=0; i<n; ++i)
        cout << ans;
    cout << endl;
    return 0;
}
