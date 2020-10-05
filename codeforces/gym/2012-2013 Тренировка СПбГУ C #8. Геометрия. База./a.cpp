#include <cpplib/stdinc.hpp>
#include <cpplib/adt/geoinc.hpp>

int32_t main(){
    desync();
    freopen("angle1.in", "r", stdin);
    freopen("angle1.out", "w", stdout);
    point<int> p, p1 = {1, 0};
    cin >> p.x >> p.y;
    auto a = angle(p, p1);
    cerr.precision(10);
    cerr << fixed;
    int xtoy = get<2>(orientation(p1, p));
    if(xtoy == -1)
        a = 2*acos(-1) - a;
    cout << fixed << setprecision(16) << a << endl;
    return 0;
}
