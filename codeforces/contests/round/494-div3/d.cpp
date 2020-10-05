#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;
    map<int, int> cnt;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        cnt[x]++;
    }
    while(q--){
        int x;
        cin >> x;
        int ans = 0;
        for(int i=(1LL<<32); i>0; i>>=1){
            if(cnt.count(i)){
                int c = min(cnt[i], x/i);
                x -= c*i;
                ans += c;
            }
        }
        cout << (x? -1 : ans) << endl;
    }
    return 0;
}
