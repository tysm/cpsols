#include <cpplib/stdinc.hpp>

int prod(tt i, int k){
    int t, x, y;
    tie(t, x, y) = i;

    if(k > t*x){
        int res = x;
        k -= t*x;

        res += (k/(y + t*x))*x;
        k %= (y + t*x);

        if(k > y)
            res += (k-y)/t;
        return res;
    }
    return k/t;
}

int compute(vtt &arr, int k){
    int res = 0;
    for(auto i:arr)
        res += prod(i, k);
    return res;
}

int32_t main(){
    desync();
    int n, m;
    cin >> m >> n;
    vtt arr;
    for(int i=0; i<n; ++i){
        int t, x, y;
        cin >> t >> x >> y;
        arr.eb(t, x, y);
    }
    int lo = 0, hi = INF, ans = INF;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(compute(arr, mid) >= m){
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    cout << ans << endl;
    for(int i=0; i<n; ++i){
        int aux = prod(arr[i], ans);
        cout << min(aux, m) << " \n"[i == n-1];
        m = (m >= aux? m-aux : 0);
    }
    return 0;
}
