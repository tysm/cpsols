#include <cpplib/stdinc.hpp>
#include <cpplib/adt/heap.hpp>

// sum(a)/sum(b) >= x
// sum(a) >= x*sum(b)
// sum(a - b*x) >= 0

bool solve(vii &arr, int k, double x){
    vd values;
    for(ii &i:arr)
        values.eb(i.ff - i.ss*x);
    sort(rall(values));
    double sum = 0;
    for(int i=0; i<k; ++i)
        sum += values[i];
    return sum > -EPS;
}

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    vii arr(n);
    for(ii &i:arr)
        cin >> i.ff >> i.ss;

    double lo = 0, hi = LINF, ans = LINF;
    while(lo < hi+EPS){
        double mid = (lo+hi)/2;
        if(solve(arr, k, mid)){
            ans = mid;
            lo = mid+EPS;
        }
        else
            hi = mid-EPS;
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
