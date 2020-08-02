#include <cpplib/stdinc.hpp>

bool check(vi &arr, int k, int mid){
    int r = 0, acc = 0;
    for(int i:arr){
        acc += (i+r)/mid;
        r = (i+r >= mid? (i+r)%mid : i);
    }
    return acc >= k;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi arr(n);
        for(int &i:arr)
            cin >> i;
        int lo = 1, hi = 2e12, ans = 0;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(check(arr, k, mid)){
                ans = mid;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        cout << ans*k << endl;
    }
    return 0;
}
