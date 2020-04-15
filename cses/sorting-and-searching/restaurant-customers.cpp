#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1619
    desync();
    int n;
    cin >> n;

    vii ops;
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        ops.pb({a, 1});
        ops.pb({b, -1});
    }
    sort(ops.begin(), ops.end());

    int cur = 0, ans = 0;
    for(ii op:ops){
        cur += op.ss;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
