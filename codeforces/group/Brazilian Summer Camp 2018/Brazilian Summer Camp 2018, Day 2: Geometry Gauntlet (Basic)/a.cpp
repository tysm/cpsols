#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>

int32_t main(){
    desync();
    point<int> p, q, a, b;

    cin >> p.x >> p.y;
    cin >> q.x >> q.y;
    point<int> v = q - p;

    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    point<int> u = b - a;

    cout << fixed << setprecision(10);
    cout << norm(v) << ' ' << norm(u) << endl;

    point<int> sum = v+u;
    cout << sum.x << ' ' << sum.y << endl;

    cout << v*u << ' ' << (v^u).z << endl;

    cout << norm(v^u)/2 << endl;
    return 0;
}
