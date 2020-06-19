#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vi cnt(26);
        for(char c:s)
            cnt[c-'a']++;
        int n;
        cin >> n;
        vi arr(n);
        for(int &i:arr)
            cin >> i;
        string ans;
        for(int i=0; i<n; ++i)
            ans += ' ';
        for(char c='z'; c>='a'; --c){
            vi idxs;
            for(int i=0; i<n; ++i){
                if(!arr[i])
                    idxs.pb(i);
            }
            if(idxs.size() > cnt[c-'a'])
                continue;
            for(int i:idxs){
                ans[i] = c;
                arr[i] = -1;
            }
            for(int i:idxs){
                for(int j=0; j<n; ++j){
                    if(arr[j] != -1)
                        arr[j] -= abs(i-j);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
