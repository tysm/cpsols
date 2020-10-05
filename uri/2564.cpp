#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    while(cin >> n){
        int ans = -1;
        for(int i=1; i<n; ++i){
            int p, r;
            cin >> p >> r;
            if(p == n)
                ans = (r != 1);
            else if(ans != -1 and r)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
