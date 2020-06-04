#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;

        int acc = 0;
        vector<string> ans(n);
        for(string &s:ans){
            cin >> s;
            for(char c:s)
                acc += (c == 'R');
        }

        vi cnt(k, acc/k);
        for(int i=0; i<acc%k; ++i)
            cnt[i]++;

        int cur = 0;
        for(int i=0; i<n; ++i){
            string &s = ans[i];
            if(i%2 == 0){
                for(int j=0; j<m; ++j){
                    if(s[j] == 'R' and cnt[cur])
                        cnt[cur]--;
                    s[j] = (cur + '0' <= '9'? cur + '0' : (cur - 10 + 'a' <= 'z'? cur - 10 + 'a' : cur - 36 + 'A'));
                    if(!cnt[cur] and cur < k-1)
                        cur++;
                }
            }
            else{
                for(int j=m-1; j>=0; --j){
                    if(s[j] == 'R' and cnt[cur])
                        cnt[cur]--;
                    s[j] = (cur + '0' <= '9'? cur + '0' : (cur - 10 + 'a' <= 'z'? cur - 10 + 'a' : cur - 36 + 'A'));
                    if(!cnt[cur] and cur < k-1)
                        cur++;
                }
            }
            cout << s << endl;
        }
    }
    return 0;
}
