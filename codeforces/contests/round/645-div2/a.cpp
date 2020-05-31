#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int ans = min((n/2)*m + (n%2)*(m/2+m%2), (m/2)*n + (m%2)*(n/2+n%2));
        cout << ans << endl;
    }
    return 0;
}
