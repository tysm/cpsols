#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi cnt(26);
        for(int i=0; i<n; ++i){
            char c;
            cin >> c;
            cnt[c-'a']++;
        }
        int ans = 0;
        for(int v=n; v>=1 and !ans; --v){
            int r = k%v;
            if(r == 0)
                ans = v;
            else{
                int c = gcd(r, v), q = v/c, acc = 0;
                for(int i=0; i<26; ++i)
                    acc += cnt[i]/q;
                if(acc >= c)
                    ans = v;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
