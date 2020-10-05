#include <cpplib/stdinc.hpp>
#define double long double

bool check(int p, vii &arr, double t){
    vector<double> res;
    for(ii &i:arr)
        res.eb(i.ss - i.ff*t);
    for(double i:res){
        if(i <= -EPS){
            double need = abs(i)/p;
            if(need >= t+EPS)
                return false;
            t -= need;
        }
    }
    return true;
}

int32_t main(){
    desync();
    int n, p;
    cin >> n >> p;

    vii arr(n);
    for(ii &i:arr)
        cin >> i.ff >> i.ss;

    double lo = 0, hi = LINF, ans = LINF;
    for(int i=0; i<500; ++i){
        double mid = lo + (hi-lo)/2;
        if(check(p, arr, mid)){
            ans = mid;
            lo = mid + EPS;
        }
        else
            hi = mid - EPS;
    }

    if(hi > 1e18)
        cout << -1 << endl;
    else
        cout << fixed << setprecision(16) << ans << endl;
    return 0;
}
