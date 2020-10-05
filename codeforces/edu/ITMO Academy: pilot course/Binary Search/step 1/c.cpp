#include <cpplib/stdinc.hpp>

int solve(vi &arr, int x){
    int lo = 0, hi = arr.size()-1, res = arr.size();
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(arr[mid] >= x){
            res = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    return res+1;
}

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    while(q--){
        int x;
        cin >> x;
        cout << solve(arr, x) << endl;
    }
    return 0;
}
