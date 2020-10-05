#include <cpplib/stdinc.hpp>

// abs(xi-x) <= t*vi
// -x <= t*vi - xi -> x >= xi - t*vi :: xi >= x
// x <= t*vi + xi -> x <= xi + t*vi :: x >= xi

bool solve(vii &arr, double t){
    double l = -LINF, r = LINF;
    for(ii &i:arr){
        l = max(l, i.ff - t*i.ss);
        r = min(r, i.ff + t*i.ss);
    }
    return l < r+EPS;
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    vii arr(n);
    for(ii &i:arr)
        cin >> i.ff >> i.ss;

    double lo = -LINF, hi = LINF, ans = LINF;
    while(lo < hi+EPS){
        double mid = (lo+hi)/2;
        if(solve(arr, mid)){
            ans = mid;
            hi = mid-EPS;
        }
        else
            lo = mid+EPS;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
