#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int ans = 0;
        for(int i=0; i<n; ++i){
            int acc = 0;
            for(int j=0; j<m; ++j){
                char c;
                cin >> c;
                if(c == '.')
                    acc++;
                else{
                    ans += min(x*acc, (acc/2)*y + (acc%2)*x);
                    acc = 0;
                }
            }
            ans += min(x*acc, (acc/2)*y + (acc%2)*x);
        }
        cout << ans << endl;
    }
    return 0;
}
