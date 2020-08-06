#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n), b(n);
        int ma = LINF, mb = LINF;
        for(int &i:a){
            cin >> i;
            ma = min(i, ma);
        }
        for(int &i:b){
            cin >> i;
            mb = min(i, mb);
        }
        int ans = 0;
        for(int i=0; i<n; ++i)
            ans += max(a[i]-ma, b[i]-mb);
        cout << ans << endl;
    }
    return 0;
}
