#include <cpplib/stdinc.hpp>

bool solve(vi &arr, int k, int t){
    for(int i:arr){
        k -= (t/i);
        if(k <= 0)
            return true;
    }
    return false;
}

int32_t main(){
    // https://cses.fi/problemset/task/1620
    desync();
    int n, k;
    cin >> n >> k;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    int lo = 0, hi = INF*INF, ans = INF*INF;
    while(lo <= hi){
        int mid = lo+(hi-lo)/2;
        if(solve(arr, k, mid)){
            ans = min(ans, mid);
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    cout << ans << endl;
    return 0;
}
