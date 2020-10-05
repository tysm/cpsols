#include <cpplib/stdinc.hpp>

bool check(vi &arr, int x){
    int lo = 0, hi = arr.size()-1;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(arr[mid] == x)
            return true;
        if(arr[mid] > x)
            hi = mid-1;
        else
            lo = mid+1;
    }
    return false;
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
        cout << (check(arr, x)? "YES" : "NO") << endl;
    }
    return 0;
}
