#include <cpplib/stdinc.hpp>
#include <cpplib/array/kadane.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    int ans = 0;
    for(int h = 30; h>=1; --h)
        ans = max(ans, kadane(arr, -INF, h).ff-h);
    cout << ans << endl;
    return 0;
}
