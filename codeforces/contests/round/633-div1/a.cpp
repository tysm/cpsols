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
        int ans = 0;
        for(int i=1; i<n; ++i){
            if(arr[i] < arr[i-1]){
                int d = arr[i-1]-arr[i];
                for(int j=0; j<34; ++j){
                    if(d & (1LL<<j))
                        ans = max(ans, j+1);
                }
                arr[i] += d;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
