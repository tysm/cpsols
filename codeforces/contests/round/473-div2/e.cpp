#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    n--;

    int ans = 0;
    for(int i=1; i<=n; i<<=1)
        ans += ((n-i)/(i<<1) + 1)*i;
    cout << ans << endl;
    return 0;
}
