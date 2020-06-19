#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vi arr;
        for(int i=0; i<n; ++i){
            if(s[i] == '1')
                arr.pb(i);
        }
        arr.pb(INF);
        int l = -INF, r = 0, ans = 0;
        for(int i=0; i<n; ++i){
            if(i == arr[r])
                l = arr[r++];
            else if(i-k>l and arr[r]-k>i){
                ans++;
                l = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
