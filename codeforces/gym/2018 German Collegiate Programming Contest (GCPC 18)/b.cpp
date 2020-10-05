#include <cpplib/stdinc.hpp>
#define double long double
#include <cpplib/adt/point.hpp>
#include <cpplib/geo/circle.hpp>

int32_t main(){
    desync();

    point<int> u, v;
    cin >> u.x >> u.y;
    cin >> v.x >> v.y;

    point<int> bc, rc;
    int br, rr;
    cin >> bc.x >> bc.y >> br;
    cin >> rc.x >> rc.y >> rr;

    point<double> up[2], vp[2];
    tie(up[0], up[1]) = tangents(u, rc, rr);
    tie(vp[0], vp[1]) = tangents(v, rc, rr);

    double ans = distance(u, v) + 2*PI*rr;
    for(int i=0; i<2; ++i){
        for(int j=0; j<2; ++j){
            double ang = angle(up[i]-rc, vp[j]-rc);
            ans = min(ans, distance(u, up[i]) + distance(v, vp[j]) + circle_arc(rr, ang));
        }
    }
    cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
