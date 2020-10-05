#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, p;
    cin >> n >> p;
    int ans = -1;
    for(int i=1; i<34 and ans == -1; ++i){
        int np = n-p*i, cnt = __builtin_popcount(np);
        if(cnt <= i and i <= np)
            ans = i;
    }
    cout << ans << endl;
    return 0;
}
