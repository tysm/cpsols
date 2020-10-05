#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<string, int> arr;
        for(int i=0; i<n; ++i){
            string s;
            cin >> s;
            arr[s] = i;
        }
        vi ans;
        ii cur = {0, 0};
        for(int i=0; i<n; ++i){
            string s;
            cin >> s;
            if(arr[s] != i)
                cur.ss = max(cur.ss, arr[s]);
            if(cur.ss == i){
                ans.eb(cur.ss - cur.ff + 1);
                cur = {i+1, i+1};
            }
        }
        cout << ans << endl;
    }
    return 0;
}
