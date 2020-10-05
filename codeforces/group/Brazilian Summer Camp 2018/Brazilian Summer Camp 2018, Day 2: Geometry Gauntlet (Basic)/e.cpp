#define double long double
#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/adt/segment.hpp>

double distance(segment<double> s, segment<double> r){
    if(intersect(s, r))
        return 0;
    return min({distance(s.a, r), distance(s.b, r), distance(r.a, s), distance(r.b, s)});
}

double distance(vector<point<double> > &pts, double t){
    vector<point<double> > pi;
    pi.eb(pts[0] + pts[2]*t);
    pi.eb(pts[1] + pts[2]*t);

    pi.eb(pts[3] + pts[5]*t);
    pi.eb(pts[4] + pts[5]*t);

    return distance(segment<double>(pi[0], pi[1]), segment<double>(pi[2], pi[3]));
}

int32_t main(){
    desync();
    vector<point<double> > pts(6);
    for(auto &p:pts)
        cin >> p.x >> p.y;
    swap(pts[4], pts[2]);
    swap(pts[3], pts[4]);

    double lo = 0, hi = 1e5;
    for(int r=0; r<=300; ++r){
        double m1 = lo + (hi-lo)/3, m2 = hi - (hi-lo)/3;
        double dm1 = distance(pts, m1), dm2 = distance(pts, m2);

        if(abs(dm1 - dm2) < EPS or dm1 < dm2)
            hi = m2;
        else
            lo = m1;
    }
    double res = (lo+hi)/2, dis = distance(pts, res);
    if(abs(dis) < 1e-6)
        cout << fixed << setprecision(10) << res << endl;
    else
        cout << -1 << endl;
    return 0;
}
