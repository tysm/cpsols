#define double long double
#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/adt/segment.hpp>

double check(point<double> pt[4], double k){
    point<double> v1 = pt[1] - pt[0];
    point<double> v2 = pt[3] - pt[2];

    v1 = v1.as_unit()*k;
    v2 = v2.as_unit()*k;
    return distance(pt[0] + v1, pt[2] + v2);
}

int32_t main(){
    desync();

    point<double> pt[4];
    for(int i=0; i<4; ++i)
        cin >> pt[i].x >> pt[i].y;

    double sqd1 = squared_norm(pt[1] - pt[0]), sqd2 = squared_norm(pt[3] - pt[2]);
    if(sqd1 > sqd2){
        swap(pt[0], pt[2]); // A por C
        swap(pt[1], pt[3]); // B por D
        // C D A B
        swap(sqd1, sqd2); 
    }
    if(distance(pt[0], pt[1]) < 1e-6){
        if(distance(pt[2], pt[3]) < 1e-6)
            cout << fixed << setprecision(16) << distance(pt[0], pt[2]) << endl;
        else
            cout << fixed << setprecision(16) << distance(pt[0], segment<double>(pt[2], pt[3])) << endl;
        return 0;
    }

    double lo = 0, hi = sqrt(sqd1);
    for(int rep=0; rep<2000; ++rep){
        double m1 = lo + (hi-lo)/3, m2 = hi - (hi-lo)/3;

        double dm1 = check(pt, m1), dm2 = check(pt, m2);
        if(dm2 > dm1)
            hi = m2;
        else
            lo = m1;
    }
    double res = (lo+hi)/2, ans = check(pt, res);

    point<double> v2 = pt[3] - pt[2];
    v2 = v2.as_unit()*sqrt(sqd1);

    if(abs(sqd1 - sqd2) > 1e-6){
        ans = min(ans,
            distance(pt[1], segment<double>(pt[2] + v2, pt[3]))
        );
    }

    cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
