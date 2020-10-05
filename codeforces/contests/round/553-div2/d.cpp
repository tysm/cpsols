#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    int ans = 0;
    vi arr;
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        arr.eb(a-b);
        ans += b*(n-1);
    }
    sort(rall(arr));

    for(int i=0; i<n; ++i)
        ans += arr[i]*i;
    cout << ans << endl;
    return 0;
}
