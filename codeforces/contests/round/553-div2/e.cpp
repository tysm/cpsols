#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi arr(n+1);
    for(int i=1; i<=n; ++i)
        cin >> arr[i];

    int ans = 0;
    for(int i=1; i<=n; ++i){
        int x = arr[i], y = arr[i-1];
        if(x > y)
            ans += (x-y)*(n-x+1);
        else
            ans += x*(y-x);
    }
    cout << ans << endl;

    return 0;
}
