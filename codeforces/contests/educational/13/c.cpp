#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    int c = lcm(a, b);
    cout << (n/a)*p + (n/b)*q - (n/c)*min(p, q) << endl;
    return 0;
}
