#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("distance2.in", "r", stdin);
    freopen("distance2.out", "w", stdout);
    point<int> a, p, q;
    cin >> a.x >> a.y >> p.x >> p.y >> q.x >> q.y;
    cout << fixed << setprecision(6) << distance(a, line<int>(p, q - p)) << endl;
    return 0;
}
