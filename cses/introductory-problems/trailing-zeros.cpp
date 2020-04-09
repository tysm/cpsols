#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1618
    desync();
    int n;
    cin >> n;
    int ans = 0;
    for(int i=5; n/i>=1; i*=5)
        ans += n/i;
    cout << ans << endl;
    return 0;
}
