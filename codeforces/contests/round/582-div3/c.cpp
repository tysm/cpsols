#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        set<int> vis;
        vi res;
        for(int cur = m; !vis.count(cur%10); cur += m){
            vis.ep(cur%10);
            res.eb(cur%10);
        }

        int d = n/m, q = d/res.size(), r = d%res.size(), ans = 0;
        for(int i=0; i<res.size(); ++i)
            ans += res[i]*q + (r > i? res[i] : 0);
        cout << ans << endl;
    }
    return 0;
}
