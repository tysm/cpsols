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
        sort(all(s));
        string ans;
        ans += s[k-1];
        if(s[0] == s[k-1] and k != n){
            if(s[k] != s[n-1])
                ans += s.substr(k);
            else{
                int r = n-k;
                for(int i=0; i<r/k; ++i)
                    ans += s[n-1];
                if(r%k)
                    ans += s[n-1];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
