#include <cpplib/stdinc.hpp>

int32_t main(){
    ifstream cin("hamming.in");
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        sort(all(a));
        sort(rall(b));
        int ans = 0;
        for(int i=0; i<n; ++i)
            ans += (a[i] != b[i]);
        cout << ans << endl;
    }
    return 0;
}
