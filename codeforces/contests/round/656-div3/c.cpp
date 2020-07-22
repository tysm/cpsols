#include <cpplib/stdinc.hpp>

bool check(vi &arr, int mid){
    int l = mid, r = arr.size()-1, cur = -1;
    while(l <= r){
        if(arr[l] < cur or arr[r] < cur)
            return false;
        if(arr[l] <= arr[r]){
            cur = arr[l];
            l++;
        }
        else{
            cur = arr[r];
            r--;
        }
    }
    return true;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi arr(n);
        for(int &i:arr)
            cin >> i;
        int lo = 0, hi = n, ans = 0;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(check(arr, mid)){
                ans = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        cout << ans << endl;
    }
    return 0;
}
