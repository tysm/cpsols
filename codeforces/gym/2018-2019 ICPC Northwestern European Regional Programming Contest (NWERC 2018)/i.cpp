#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    sort(all(arr));
    bool valid = true;
    double ans = 1;
    for(int i=1; i<=n and valid; ++i){
        if(arr[i-1] > i)
            valid = false;
        else
            ans = min(ans, (double)arr[i-1]/i);
    }
    if(valid)
        cout << fixed << setprecision(10) << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
