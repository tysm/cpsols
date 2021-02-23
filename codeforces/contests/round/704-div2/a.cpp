#include <cpplib/stdinc.hpp>

void solve(){
    int p, a, b, c;
    cin >> p >> a >> b >> c;

    int ans = LINF;
    ans = min(ans, (a-p%a)%a);
    ans = min(ans, (b-p%b)%b);
    ans = min(ans, (c-p%c)%c);

    cout << ans << endl;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
