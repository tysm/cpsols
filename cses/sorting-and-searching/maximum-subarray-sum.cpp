#include <cpplib/stdinc.hpp>

int mss(vi &arr, int l, int r){
    if(l == r)
        return arr[l];

    int mid = (l+r)/2, ans = -INF, sum = 0;
    for(int i=mid; i>=l; --i){
        sum += arr[i];
        ans = max(sum, ans);
    }
    sum = ans;
    for(int i=mid+1; i<=r; ++i){
        sum += arr[i];
        ans = max(sum, ans);
    }
    return max({ans, mss(arr, l, mid), mss(arr, mid+1, r)});
}

int32_t main(){
    // https://cses.fi/problemset/task/1643
    desync();
    int n;
    cin >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    cout << mss(arr, 0, n-1) << endl;
    return 0;
}
