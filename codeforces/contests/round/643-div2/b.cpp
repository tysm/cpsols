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
        sort(all(arr));
        int ans = 0, cnt = 0, cur = 0;
        for(int i:arr){
            cur = max(i, cur);
            cnt++;
            if(cnt == cur){
                cnt = cur = 0;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
