#include <cpplib/stdinc.hpp>

bool fit(int n, int h, int w, int x){
    return (x/h)*(x/w) >= n;
}

int32_t main(){
    desync();
    int h, w, n;
    cin >> h >> w >> n;
    int lo = 1;
    while(!fit(n, h, w, lo<<1))
        lo <<= 1;
    int hi = lo<<1, ans = hi;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(fit(n, h, w, mid)){
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    cout << ans << endl;
    return 0;
}
