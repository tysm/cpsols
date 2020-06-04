#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m, ans = 0;
        cin >> n >> m;
        for(int i=0; i<n; ++i){
            int c;
            cin >> c;
            ans += c*2;
        }
        if(n > 2 and m == n){
            cout << ans << endl;
            for(int i=1; i<=n; ++i)
                cout << i << ' ' << (i%n)+1 << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
