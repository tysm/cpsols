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
        sort(arr.begin(), arr.end());
        int ans = INF;
        for(int i=1; i<n; ++i)
            ans = min(ans, arr[i]-arr[i-1]);
        cout << ans << endl;
    }
    return 0;
}
