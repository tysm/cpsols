#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("raydist.in", "r", stdin);
    freopen("raydist.out", "w", stdout);
    point<int> a, b, p, q;
    cin >> a.x >> a.y >> b.x >> b.y >> p.x >> p.y >> q.x >> q.y;
    ray<double> r(a, b - a), s(p, q - p);
    if(!r.v.is_null())
        r.v = r.v.as_unit();
    if(!s.v.is_null())
        s.v = s.v.as_unit();
    cout << fixed << setprecision(5) << distance(r, s) << endl;
    return 0;
}
