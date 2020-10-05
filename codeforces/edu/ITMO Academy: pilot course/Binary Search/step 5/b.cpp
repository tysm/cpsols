#include <cpplib/stdinc.hpp>

int calc(int n, int x){
    int res = 0;
    for(int i=1; i<=n; ++i){
        int j = x/i;
        if(i*j == x)
            j--;
        res += min(j, n);
    }
    return res;
}

bool check(int n, int x){
    for(int i=1; i<=n; ++i){
        int j = x/i;
        if(i*j == x and j <= n)
            return true;
    }
    return false;
}

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    k--;

    int lo = 1, hi = n*n;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        int resx = calc(n, mid), resxp1 = calc(n, mid+1);
        if(resx <= k and resxp1 > k and check(n, mid)){
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
