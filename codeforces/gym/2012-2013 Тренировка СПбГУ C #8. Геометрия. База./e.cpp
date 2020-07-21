#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("bisector.in", "r", stdin);
    freopen("bisector.out", "w", stdout);
    point<int> x, y, z;
    cin >> x.x >> x.y >> y.x >> y.y >> z.x >> z.y;

    point<double> d = x + bisector(y - x, z - x);
    double a = d.y - x.y, b = x.x - d.x, c = -(a*d.x + b*d.y);
    cout << fixed << setprecision(16) << a << ' ' << b << ' ' << c << endl;
    return 0;
}
