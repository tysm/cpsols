#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    double c;
    cin >> c;

    auto func = [](double x){ return x*x + sqrt(x); };

    double lo = EPS, hi = 1e5;
    while(lo < hi + EPS){
        double mid = (lo+hi)/2, res = func(mid);

        if(abs(res-c) < EPS){
            cout << fixed << setprecision(10) << mid << endl;
            return 0;
        }

        if(res <= c-EPS)
            lo = mid+EPS;
        else
            hi = mid-EPS;
    }
    cout << fixed << setprecision(10) << lo << endl;
    return 0;
}
