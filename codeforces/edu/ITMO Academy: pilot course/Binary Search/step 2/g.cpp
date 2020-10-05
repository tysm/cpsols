#include <cpplib/stdinc.hpp>

bool check(vi &arr, int k, int m){
    int cnt = 0, acc = 0;
    for(int i:arr){
        acc += min(i, k);
        cnt += acc/k;
        acc %= k;
    }
    return cnt >= m;
}

int32_t main(){
    desync();
    int n, m;
    cin >> m >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    int lo = 0, hi = n*INF, ans = 0;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(check(arr, mid, m)){
            ans = mid;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    cout << ans << endl;
    return 0;
}
