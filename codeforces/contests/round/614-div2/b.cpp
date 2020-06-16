#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    double ans = 0;
    for(int i=n; i>=1; --i)
        ans += (double)1/i;
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}
