#include <cpplib/stdinc.hpp>

bool solve(vi &arr, int k, int sum){
    int acc = 0, cnt = 0;
    for(int i=0; i<arr.size(); ++i){
        if(acc == 0)
            cnt++;
        if(arr[i] > sum)
            return false;
        if(arr[i] + acc <= sum){
            acc += arr[i];
            if(acc == sum)
                acc = 0;
        }
        else{
            acc = 0;
            i--;
        }
    }
    return cnt <= k;
}

int32_t main(){
    // https://cses.fi/problemset/task/1085
    desync();
    int n, k;
    cin >> n >> k;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    int lo = 1, hi = 2e14, ans = hi;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(solve(arr, k, mid)){
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    cout << ans << endl;
    return 0;
}
