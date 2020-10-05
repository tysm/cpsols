#include <cpplib/stdinc.hpp>
#define double long double
#include <cpplib/adt/circle.hpp>

int32_t main(){
    desync();
    point<int> c1, c2;
    int r1, r2;
    cin >> c1.x >> c1.y >> r1 >> c2.x >> c2.y >> r2;

    circle<int> a(c1, r1), b(c2, r2);
    cout << fixed << setprecision(16) << intersection_area(a, b) << endl;
    return 0;
}
