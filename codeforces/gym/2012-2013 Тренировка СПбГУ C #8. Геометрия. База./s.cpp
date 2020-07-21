#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("position.in", "r", stdin);
    freopen("position.out", "w", stdout);
    point<int> p, q;
    int a, b, c;
    cin >> p.x >> p.y >> q.x >> q.y >> a >> b >> c;

    line<double> l = make_line2d(a, b, c);
    auto lp = projection(p, l), lq = projection(q, l);

    cout << ((p - lp)*(q - lq) > 0? "YES" : "NO") << endl;
    return 0;
}
