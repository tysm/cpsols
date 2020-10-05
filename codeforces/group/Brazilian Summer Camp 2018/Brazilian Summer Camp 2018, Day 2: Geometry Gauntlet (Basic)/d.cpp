#include <cpplib/stdinc.hpp>
#include <cpplib/adt/triangle.hpp>

int32_t main(){
    desync();
    point<int> tri[3];
    for(int i=0; i<3; ++i)
        cin >> tri[i].x >> tri[i].y;

    triangle<int> t(tri[0], tri[1], tri[2]);

    auto ic = t.incenter();
    auto r = t.inradius();
    cout << fixed << setprecision(10) << ic.x << ' ' << ic.y << ' ' << r << endl;
    return 0;
}
