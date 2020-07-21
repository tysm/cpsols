#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("area1.in", "r", stdin);
    freopen("area1.out", "w", stdout);
    point<int> a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    cout << fixed << setprecision(16) << norm((a-b)^(c-b))/2 << endl;
    return 0;
}
