#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        map<int, int> cnt;
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            if(x%k)
                cnt[k - x%k]++;
        }
        int x = 0;
        for(ii i:cnt)
            x = max(x, i.ff + (i.ss-1)*k + 1);
        cout << x << endl;
    }
    return 0;
}
