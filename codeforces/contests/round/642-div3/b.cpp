#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi a(n), b(n);
        for(int &i:a)
            cin >> i;
        for(int &i:b)
            cin >> i;
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        int ans = 0;
        for(int i=0; i<n; ++i){
            if(k > 0 and b[i] > a[i]){
                ans += b[i];
                k--;
            }
            else
                ans += a[i];
        }
        cout << ans << endl;
    }
    return 0;
}
