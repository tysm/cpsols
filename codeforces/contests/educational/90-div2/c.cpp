#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ans = 0, cnt = 0, acc = 0;
        for(int i=0; i<s.size(); ++i){
            ans += 1;
            if(s[i] == '+')
                acc--;
            else
                acc++;
            if(acc > cnt){
                cnt = acc;
                ans += i+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
