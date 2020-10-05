#include <cpplib/stdinc.hpp>

int calc(vii &arr, int x){
    int res = 0;
    for(ii &i:arr){
        if(x > i.ss)
            res += i.ss-i.ff+1;
        else if(x >= i.ff)
            res += x-i.ff;
    }
    return res;
}

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    vii arr(n);
    for(ii &i:arr)
        cin >> i.ff >> i.ss;

    int lo = -INF, hi = INF;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        int resx = calc(arr, mid), resxp1 = calc(arr, mid+1);
        if(resx <= k and resxp1 > k){
            cout << mid << endl;
            break;
        }
        if(resx > k)
            hi = mid-1;
        else
            lo = mid+1;
    }
    return 0;
}
