#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cur = 0;
        set<int> nxt;
        vi ans(n);
        bool ok = true;
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;

            if(!ok)
                continue;
            if(x < cur){
                ok = false;
                continue;
            }

            if(x > cur){
                ans[i] = x;
                for(int j=cur+1; j<x; ++j)
                    nxt.emplace(-j);
            }
            else{
                if(nxt.empty()){
                    ok = false;
                    continue;
                }
                ans[i] = -(*nxt.begin());
                nxt.erase(nxt.begin());
            }
            cur = x;
        }
        if(ok)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
