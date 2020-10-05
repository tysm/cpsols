#include <cpplib/stdinc.hpp>

bool check(vi &a, vi &b, int d){
    int n = a.size();
    for(int i=0; i<n; ++i){
        if(a[i] + d > b[i])
            return true;
        else if(a[i] + d < b[i])
            return false;
    }
    return true;
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi a(n), b(n);
    for(int &i:a)
        cin >> i;
    for(int &i:b)
        cin >> i;

    int lo = 0, hi = 1001, ans = 1001;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(check(a, b, mid)){
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    cout << ans << endl;
    return 0;
}
