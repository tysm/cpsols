#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("point1.in", "r", stdin);
    freopen("point1.out", "w", stdout);
    point<int> p;
    cin >> p.x >> p.y;

    int a, b, c;
    cin >> a >> b >> c;

    line<double> l = make_line2d(a, b, c);

    cout << (count(l, p)? "YES" : "NO") << endl;
    return 0;
}
