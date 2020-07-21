#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("distance5.in", "r", stdin);
    freopen("distance5.out", "w", stdout);
    point<int> a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

    segment<int> s(a, b), r(c, d);
    cout << fixed << setprecision(16) << distance(s, r) << endl;
    return 0;
}
