#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("length.in", "r", stdin);
    freopen("length.out", "w", stdout);
    point<int> p, q;
    cin >> p.x >> p.y >> q.x >> q.y;
    cout << fixed << setprecision(16) << norm(q - p) << endl;
    return 0;
}
