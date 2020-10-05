#include <cpplib/stdinc.hpp>

// sum(l...r)/(r-l+1) >= x (mean)
// x*(r-l+1) <= sum(r) - sum(l-1)
// 0 <= sumx(r) - sumx(l-1)
// sumx(l-1) <= sumx(r)

bool solve(vi &arr, int d, double x, int &resL, int &resR){
    int n = arr.size();

    vd psum(n+1);

    vector<pair<double, int> > mval;
    mval.eb(0, 0);

    for(int i=1; i<=n; ++i){
        psum[i] = arr[i-1] - x + psum[i-1];
        mval.eb(psum[i], i);
        if(mval[i-1] < mval[i])
            mval[i] = mval[i-1];
    }

    for(int r=d; r<=n; ++r){
        if(psum[r] >= mval[r-d].ff){
            resR = r;
            resL = mval[r-d].ss+1;
            return true;
        }
    }
    return false;
}

int32_t main(){
    desync();
    int n, d;
    cin >> n >> d;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    int resL = 1, resR = n;
    double lo = 0, hi = 100*n;
    while(lo <= hi){
        double mid = (lo+hi)/2;
        if(solve(arr, d, mid, resL, resR))
            lo = mid+EPS;
        else
            hi = mid-EPS;
    }

    cout << resL << ' ' << resR << endl;
    return 0;
}
