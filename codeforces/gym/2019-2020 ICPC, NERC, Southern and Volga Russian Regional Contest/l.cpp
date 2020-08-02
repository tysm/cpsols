#include <cpplib/stdinc.hpp>

bool solve(int a, int b, int c, int mid){
    a -= mid;
    c -= mid;
    if(a > 0 and c > 0)
        return false;
    else if(a > 0){
        b = max((int)0, b+c);
        return b+a <= mid;
    }
    else if(c > 0){
        b = max((int)0, b+a);
        return b+c <= mid;
    }
    return a + b + c <= mid;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int lo = 1, hi = a+b+c, ans = max({a, b, c});
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(solve(a, b, c, mid)){
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
