#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("point3.in", "r", stdin);
    freopen("point3.out", "w", stdout);
    point<int> p, a, b;
    cin >> p.x >> p.y >> a.x >> a.y >> b.x >> b.y;
    segment<int> s(a, b);
    cout << (count(s, p)? "YES" : "NO") << endl;
    return 0;
}
