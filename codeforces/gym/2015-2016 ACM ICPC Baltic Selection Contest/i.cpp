#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/adt/line.hpp>

bool check(line<double> l1, line<double> t, line<double> l2, point<double> p){
    double dis = distance(p, l1);
    dis = min(distance(p, l2), dis);
    dis = min(distance(p, t), dis);
    return p.y < dis+EPS;
}

int32_t main(){
    double r, R, h;
    cin >> r >> R >> h;
    double d = 2*r, D = 2*R;

    point<double> p0, p1(D, 0), p2((D-d)/2, h), p3((D-d)/2+d, h);
    line<double> l1(p0, p2), t(p2, p3), l2(p3, p1);

    double lo = EPS, hi = h/2, ans = h/2;
    while(lo < hi + EPS){
        double mid = (lo+hi)/2;
        if(check(l1, t, l2, point<double>(D/2, mid))){
            ans = mid;
            lo = mid+EPS; // n precisa kkkkk mas eu gosto
        }
        else
            hi = mid-EPS;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
