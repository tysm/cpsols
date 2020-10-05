#include <cpplib/stdinc.hpp>
#define double long double
#include <cpplib/adt/point.hpp>
#include <cpplib/geo/cvhull.hpp>

bool check(vector<point<double> > &arr, double d){
    int n = arr.size();

    point<double> mid;
    for(auto i:arr)
        mid += i;
    mid /= n;

    bool ok = true;
    for(int i=0; i<n; ++i){
        vector<point<double> > aux(arr);
        auto v = mid-aux[i];
        aux[i] += v*(d/norm(v));
        for(int j=0; j<n; ++j){
            if(j == i)
                continue;
            aux[j] -= v*(d/norm(v));
        }
        if(get<0>(convex_hull(aux)).size() < n)
            ok = false;
    }
    return ok;
}

int32_t main(){
    int n;
    cin >> n;

    vector<point<double> > arr(n);
    for(auto &i:arr)
        cin >> i.x >> i.y;


    double lo = 0, hi = LINF, ans = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(j == i)
                continue;
            hi = min(hi, distance(arr[i], arr[j]));
        }
    }
    hi /= 2;

    while(lo < hi + EPS){
        double mid = (lo+hi)/2;
        if(check(arr, mid)){
            ans = mid;
            lo = mid+EPS;
        }
        else
            hi = mid-EPS;
    }
    cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
