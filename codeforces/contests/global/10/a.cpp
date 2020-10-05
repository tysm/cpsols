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
        int cur = 0, ans = 1;
        for(int i=0; i<n; ++i){
            debug(cur);
            debug(arr[i]);
            if(cur != arr[i])
                cur += arr[i];
            else{
                cur = arr[i];
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
