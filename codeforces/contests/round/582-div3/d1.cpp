#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    map<int, vi> ops;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        int cur = 0;
        ops[x].eb(cur);
        while(x != 0){
            x /= 2;
            cur++;
            ops[x].eb(cur);
        }
    }
    int ans = INF;
    for(auto &[x, vals] : ops){
        if(vals.size() < k)
            continue;
        sort(all(vals));
        int res = 0;
        for(int i=0; i<k; ++i)
            res += vals[i];
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}
