#include <cpplib/stdinc.hpp>

int solve(vi &arr, int k){
    int cnt = 0, sum = 0;
    for(int i:arr){
        if(sum + i > k){
            sum = 0;
            cnt++;
        }
        sum += i;
    }
    return cnt+1;
}

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    int lo = *max_element(all(arr)), hi = lo*n, ans = hi;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2, res = solve(arr, mid);
        if(res <= k){
            hi = mid-1;
            ans = mid;
        }
        else
            lo = mid+1;
    }
    cout << ans << endl;
    return 0;
}
