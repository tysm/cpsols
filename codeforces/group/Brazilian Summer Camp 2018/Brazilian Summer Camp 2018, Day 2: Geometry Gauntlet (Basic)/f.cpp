#include <cpplib/stdinc.hpp>
#include <cpplib/adt/circle.hpp>
#include <cpplib/adt/segment.hpp>

int32_t main(){
    desync();
    point<int> a, b;
    cin >> a.x >> a.y >> b.x >> b.y;

    point<int> c;
    cin >> c.x >> c.y;
    int r;
    cin >> r;

    circle<int> cir(c, r);

    point<double> cl = closest(c, segment<int>(a, b));

    cout << fixed << setprecision(10);
    if(distance(cl, c) < r){
        auto [a1, a2] = cir.tangents(a);
        auto [b1, b2] = cir.tangents(b);

        double anga1b2 = angle(a1 - c, b2 - c);
        double anga2b1 = angle(a2 - c, b1 - c);

        double ans = min(distance(a, a1) + distance(b, b2) + cir.arc(anga1b2),
                distance(a, a2) + distance(b, b1) + cir.arc(anga2b1));
        cout << ans << endl;
    }
    else
        cout << distance(a, b) << endl;
    return 0;
}
