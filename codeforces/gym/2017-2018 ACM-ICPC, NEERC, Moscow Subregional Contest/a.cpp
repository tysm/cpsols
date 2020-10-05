#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    if(k >= n){
        cout << 1 << endl;
        return 0;
    }
    int b = k, lo = 0, hi = 32, acc = 0;
    while(lo <= hi){
        int mid = (lo+hi)/2, bi = b*(1<<mid);
        if(bi >= (n-bi)/2){
            acc = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    debug(acc);
    n -= b*(1<<acc);
    debug(n);
    debug(b*(1<<acc));
    cout << acc + (int)log2(n) << endl;
    return 0;
}
