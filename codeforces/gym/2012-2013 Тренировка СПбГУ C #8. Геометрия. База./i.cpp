#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("distance4.in", "r", stdin);
    freopen("distance4.out", "w", stdout);
    point<int> p, a, b;
    cin >> p.x >> p.y >> a.x >> a.y >> b.x >> b.y;
    cout << fixed << setprecision(6) << distance(p, segment<int>(a, b)) << endl;
    return 0;
}
