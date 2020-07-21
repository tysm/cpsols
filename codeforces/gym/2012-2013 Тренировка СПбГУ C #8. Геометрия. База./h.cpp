#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("distance3.in", "r", stdin);
    freopen("distance3.out", "w", stdout);
    point<int> a, p, q;
    cin >> a.x >> a.y >> p.x >> p.y >> q.x >> q.y;
    ray<int> r(p, q - p);
    cout << fixed << setprecision(16) << distance(a, r) << endl;
    return 0;
}
