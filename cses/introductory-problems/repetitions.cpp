#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1069
    desync();
    string s;
    cin >> s;
    char last = 0;
    int cur = 0, ans = 0;
    for(char c:s){
        if(c == last)
            cur++;
        else
            cur = 1;
        ans = max(ans, cur);
        last = c;
    }
    cout << ans << endl;
    return 0;
}
