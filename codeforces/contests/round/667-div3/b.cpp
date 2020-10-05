#include <cpplib/stdinc.hpp>

int solve(int a, int b, int x, int y, int n){
    int ai = max(x, a-n);
    n -= a-ai;
    int bi = max(y, b-n);
    n -= b-bi;
    return ai*bi;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        int ans = a*b;
        ans = min(ans, solve(a, b, x, y, n));
        ans = min(ans, solve(b, a, y, x, n));
        cout << ans << endl;
    }
    return 0;
}
