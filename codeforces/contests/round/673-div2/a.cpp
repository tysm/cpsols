#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vi arr(n);
        for(int &i:arr)
            cin >> i;
        sort(all(arr));
        int ans = 0;
        for(int i=1; i<n; ++i)
            ans += (k-arr[i])/arr[0];
        cout << ans << endl;
    }
    return 0;
}
