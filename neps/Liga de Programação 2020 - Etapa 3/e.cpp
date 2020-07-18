#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int ans = ((n-1)/49)*2;
    n = 1 + (n-1)%49;
    ans += (n >= 1);
    ans += (n >= 5);
    cout << ans << endl;
    return 0;
}
