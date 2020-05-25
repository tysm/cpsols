#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<string> arr(n);
        for(string &s:arr)
            cin >> s;

        map<string, int> cnt;
        for(string &s:arr){
            cnt[s]++;
            for(int i=0; i<m; ++i){
                char si = s[i];
                for(char c='a'; c<='z'; ++c){
                    if(c == si)
                        continue;
                    s[i] = c;
                    cnt[s]++;
                }
                s[i] = si;
            }
        }
        string ans;
        for(pair<string, int> res:cnt){
            if(res.ss >= n)
                ans = res.ff;
        }
        if(ans.size() == 0)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
