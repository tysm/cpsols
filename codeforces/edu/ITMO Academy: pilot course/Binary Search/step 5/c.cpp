#include <cpplib/stdinc.hpp>

int calc(vi &a, vi &b, int x){
    int res = 0;
    for(int i:a){
        int lss = lower_bound(all(b), x-i) - b.begin();
        res += lss;
    }
    return res;
}

bool check(vi &a, vi &b, int x){
    for(int i:a){
        auto it = lower_bound(all(b), x-i);
        if(it != b.end() and *it == x-i)
            return true;
    }
    return false;
}

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    k--;

    vi a(n), b(n);
    for(int &i:a)
        cin >> i;
    for(int &i:b)
        cin >> i;
    sort(all(a));
    sort(all(b));

    int lo = 1, hi = INF;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        int resx = calc(a, b, mid), resxp1 = calc(a, b, mid+1);
        if(resx <= k and resxp1 > k and check(a, b, mid)){
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
