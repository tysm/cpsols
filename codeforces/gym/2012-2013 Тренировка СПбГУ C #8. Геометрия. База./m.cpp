#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("line1.in", "r", stdin);
    freopen("line1.out", "w", stdout);
    point<int> p, q;
    cin >> p.x >> p.y >> q.x >> q.y;
    int a, b, c;
    tie(a, b, c) = line2d_coefficients(line<int>(p, q - p));
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}
