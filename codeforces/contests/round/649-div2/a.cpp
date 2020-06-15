#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vi arr(n);
        for(int i=0; i<n; ++i)
            cin >> arr[i];
        int ans = -1, acc = 0;
        for(int i=0; i<n; ++i){
            acc += arr[i];
            if(acc%x)
                ans = max(ans, i+1);
        }
        acc = 0;
        for(int i=0; i<n; ++i){
            acc += arr[n-1-i];
            if(acc%x)
                ans = max(ans, i+1);
        }
        cout << ans << endl;
    }
    return 0;
}
