#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vi cnta(1e3+1), cntb(1e3+1);
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            cnta[x]++;
        }
        for(int i=0; i<m; ++i){
            int x;
            cin >> x;
            cntb[x]++;
        }
        int ans = -1;
        for(int i=1; i<=1e3; ++i){
            if(cnta[i] and cntb[i])
                ans = i;
        }
        if(ans == -1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl << 1 << ' ' << ans << endl;
    }
    return 0;
}
