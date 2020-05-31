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
        int ans = 1;
        for(int i=0; i<n; ++i){
            int cnt = i+1;
            if(cnt >= arr[i])
                ans = cnt+1;
        }
        cout << ans << endl;
    }
    return 0;
}
