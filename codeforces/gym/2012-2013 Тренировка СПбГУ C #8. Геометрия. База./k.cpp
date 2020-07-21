#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("intersec1.in", "r", stdin);
    freopen("intersec1.out", "w", stdout);
    int a, b, c;

    cin >> a >> b >> c;
    line<double> l = make_line2d(a, b, c);

    cin >> a >> b >> c;
    line<double> r = make_line2d(a, b, c);

    auto its = intersection(l, r);
    cout << fixed << setprecision(16) << its.p.x << ' ' << its.p.y << endl;
    return 0;
}
