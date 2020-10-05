#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi arr(2*n);
    for(int &i:arr)
        cin >> i;
    sort(all(arr));

    int h = arr[2*n-1] - arr[n], w = arr[n-1] - arr[0], ans = h*w;
    for(int i=1; i<n; ++i){
        h = arr[i+n-1] - arr[i], w = arr[2*n-1] - arr[0];
        ans = min(h*w, ans);
    }
    cout << ans << endl;
    return 0;
}
