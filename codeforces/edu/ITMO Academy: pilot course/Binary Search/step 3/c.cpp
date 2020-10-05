#include <cpplib/stdinc.hpp>

bool solve(vi &arr, int n, int d){
    int cur = arr[0];
    for(int i=1; i<n; ++i){
        if(lower_bound(all(arr), cur+d) != arr.end())
            cur = *lower_bound(all(arr), cur+d);
        else
            return false;
    }
    return true;
}

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    int lo = 1, hi = 1e9*n, ans = hi;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(solve(arr, k, mid)){
            ans = mid;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    cout << ans << endl;
    return 0;
}
