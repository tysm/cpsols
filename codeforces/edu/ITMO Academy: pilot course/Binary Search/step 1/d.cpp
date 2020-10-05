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
    return res;
}

int32_t main(){
    desync();
    int n, q;
    cin >> n;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    sort(all(arr));
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << solve(arr, r+1) - solve(arr, l) << " \n"[!q];
    }
    return 0;
}
