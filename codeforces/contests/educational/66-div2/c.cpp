#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vi a(n);
        for(int &i:a)
            cin >> i;
        sort(all(a));

        ii ans(INF, -1);
        for(int i=0; i<n-k; ++i){
            int d = a[i+k]-a[i];
            ans = min(ans, ii(d, a[i]+d/2));
        }
        cout << ans.ss << endl;
    }
    return 0;
}
