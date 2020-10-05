#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, r1, r2;
    cin >> n >> r1 >> r2;
    double a = acos(-1)/n, ans = n*(((double)r1*r2)*sin(a));
    cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
