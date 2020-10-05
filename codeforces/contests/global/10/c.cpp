#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi arr(n);
        for(int i=0; i<n; ++i)
            cin >> arr[i];
        int ans = 0;
        for(int i=n-1; i>0; --i){
            if(arr[i] >= arr[i-1])
                continue;
            ans += arr[i-1] - arr[i];
        }
        cout << ans << endl;
    }
    return 0;
}
