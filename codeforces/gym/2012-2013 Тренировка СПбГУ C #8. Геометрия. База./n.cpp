#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("line2.in", "r", stdin);
    freopen("line2.out", "w", stdout);
    point<int> p, v;
    cin >> p.x >> p.y >> v.y >> v.x;
    v.x = -v.x;
    int a, b, c;
    tie(a, b, c) = line2d_coefficients(line<int>(p, v));
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}
