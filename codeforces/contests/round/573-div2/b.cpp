#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    map<string, int> cnt;
    for(int i=0; i<3; ++i){
        string s;
        cin >> s;
        cnt[s]++;
    }
    int ans = 3;
    for(char c:{'s', 'm', 'p'}){
        for(char i='1'; i<='9'; ++i){
            string cur;
            cur += i;
            cur += c;
            if(cnt.count(cur))
                ans = min(ans, 3-cnt[cur]);

            if(i <= '7'){
                int acc = cnt.count(cur);
                string cur1, cur2;
                cur1 += (i+1);
                cur1 += c;
                cur2 += (i+2);
                cur2 += c;
                acc += cnt.count(cur1);
                acc += cnt.count(cur2);

                ans = min(ans, 3-acc);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
