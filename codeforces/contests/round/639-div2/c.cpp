#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi cnt(n);
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            cnt[mod(i+x, n)]++;
        }
        bool valid = true;
        for(int i:cnt)
            valid &= (i == 1);
        if(valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
