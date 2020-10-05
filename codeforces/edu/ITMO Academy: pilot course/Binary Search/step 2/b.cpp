#include <cpplib/stdinc.hpp>

bool cut(vd &arr, double sz, int k){
    int cnt = 0;
    for(double r:arr)
        cnt += floor(r/sz);
    return cnt >= k;
}

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    vd arr(n);
    for(double &i:arr)
        cin >> i;

    double lo = EPS, hi = 1e7, ans = 1e7;
    while(lo < hi + EPS){
        double mid = (lo+hi)/2;
        if(cut(arr, mid, k)){
            ans = mid;
            lo = mid+EPS;
        }
        else
            hi = mid-EPS;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
