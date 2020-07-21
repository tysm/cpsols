#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("line3.in", "r", stdin);
    freopen("line3.out", "w", stdout);
    double a, b, c, r;
    cin >> a >> b >> c >> r;

    line<double> l = make_line2d(a, b, c);
    point<double> ov = point<double>(l.v.y, -l.v.x).as_unit();
    point<double> p = l.p - r*ov, q = l.p + r*ov;

    tie(a, b, c) = line2d_coefficients(line<double>(p, l.v));
    cout << fixed << setprecision(16) << a << ' ' << b << ' ' << c << endl;

    tie(a, b, c) = line2d_coefficients(line<double>(q, l.v));
    cout << fixed << setprecision(16) << a << ' ' << b << ' ' << c << endl;
    return 0;
}
