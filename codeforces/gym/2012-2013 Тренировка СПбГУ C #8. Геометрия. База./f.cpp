#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("distance1.in", "r", stdin);
    freopen("distance1.out", "w", stdout);
    point<int> p;
    cin >> p.x >> p.y;
    int a, b, c;
    cin >> a >> b >> c;
    line<double> l = make_line2d(a, b, c);

    cout << fixed << setprecision(16) << distance(p, l) << endl;
    return 0;
}
