#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int h, l;
    cin >> h >> l;
    double ans = (double)(l*l-h*h)/(2*h);
    cout << setprecision(12) << fixed << ans << endl;
    return 0;
}
