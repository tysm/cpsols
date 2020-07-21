#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("angle2.in", "r", stdin);
    freopen("angle2.out", "w", stdout);
    point<int> p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cout << fixed << setprecision(16) << angle(p1, p2) << endl;
    return 0;
}
