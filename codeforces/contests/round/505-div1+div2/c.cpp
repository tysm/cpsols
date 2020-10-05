#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    string s;
    cin >> s;
    s += s;
    int cur = 0, ans = 0, lst = '2';
    for(char c:s){
        if(c == lst)
            cur = 1;
        else
            cur++;
        lst = c;
        ans = max(ans, min((int)s.size()/2, cur));
    }
    cout << ans << endl;
    return 0;
}
