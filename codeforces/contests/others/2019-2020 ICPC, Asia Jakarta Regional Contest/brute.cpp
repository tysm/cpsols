#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    double ans = 0;
    vii arr(n);
    for(auto &[a, b]:arr){
        int x, y;
        cin >> x >> y;

        ans = max(ans, (double)(x*y)/2);
        for(auto [l, r]:arr){
            ans = max(ans, (double)(min(x, l)*min(r, y)));
            ans = max(ans, (double)(min(x, r)*min(l, y)));
        }
        a = x;
        b = y;
    }
    cout << fixed << setprecision(1) << ans << endl;
    return 0;
}
