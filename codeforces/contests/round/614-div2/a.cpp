#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, s, k;
        cin >> n >> s >> k;
        set<int> arr;
        for(int i=0; i<k; ++i){
            int x;
            cin >> x;
            arr.insert(x);
        }
        int ans = INF;
        for(int i=s; i<=n; ++i){
            if(!arr.count(i)){
                ans = i-s;
                break;
            }
        }
        for(int i=s; i>=1; --i){
            if(!arr.count(i)){
                ans = min(ans, s-i);
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
