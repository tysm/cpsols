#include <cpplib/stdinc.hpp>

bool has7(int x){
    for(char c:to_string(x)){
        if(c == '7')
            return true;
    }
    return false;
}

int32_t main(){
    desync();
    int x;
    cin >> x;
    int h, m;
    cin >> h >> m;
    int ans = 0;
    while(!has7(h) and !has7(m)){
        ans++;
        m -= x;
        if(m < 0){
            h--;
            m = (m%60 + 60)%60;
        }
        if(h < 0)
            h = (h%24 + 24)%24;
    }
    cout << ans << endl;
    return 0;
}
