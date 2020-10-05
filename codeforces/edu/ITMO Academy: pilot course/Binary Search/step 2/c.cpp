#include <cpplib/stdinc.hpp>

bool check(int n, int x, int y, int t){
    t -= x;
    return 1 + t/x + t/y >= n;
}

int32_t main(){
    desync();
    int n, x, y;
    cin >> n >> x >> y;
    if(x > y)
        swap(x, y);
    int lo = x, hi = INF, ans = INF;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(check(n, x, y, mid)){
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    cout << ans << endl;
    return 0;
}
