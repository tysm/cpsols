#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("point2.in", "r", stdin);
    freopen("point2.out", "w", stdout);
    point<int> a, p, q;
    cin >> a.x >> a.y >> p.x >> p.y >> q.x >> q.y;
    ray<int> r(p, q - p);
    cout << (count(r, a)? "YES" : "NO") << endl;
    return 0;
}
