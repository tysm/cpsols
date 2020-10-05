#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    double n, a, p;
    cin >> n >> a >> p;
    cout << fixed << setprecision(16) << n + a*(p - (100 - p))/100 << endl;
    return 0;
}
