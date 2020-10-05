#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vi res;
        int cur = 0;
        for(int i=0; i<n; ++i){
            if(s[i] == '1')
                cur++;
            else{
                if(cur)
                    res.eb(cur);
                cur = 0;
            }
        }
        if(cur)
            res.eb(cur);
        sort(rall(res));
        int ans = 0;
        for(int i=0; i<res.size(); i+=2)
            ans += res[i];
        cout << ans << endl;
    }
    return 0;
}
