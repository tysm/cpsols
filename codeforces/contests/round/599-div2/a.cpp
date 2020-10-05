#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi arr(n);
        for(int &i:arr)
            cin >> i;
        sort(rall(arr));
        int ans = 0;
        for(int i=1; i<=n; ++i)
            ans = max(ans, min(i, arr[i-1]));
        cout << ans << endl;
    }
    return 0;
}
