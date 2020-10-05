#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi arr(1001);
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            arr[x]++;
        }
        int ans = 0;
        for(int i=1; i<=1000; ++i){
            if(arr[i] > arr[ans])
                ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}
