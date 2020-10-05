#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    int fact[n+1] = {};
    fact[0] = 1;
    for(int i=1; i<=n; ++i)
        fact[i] = i*fact[i-1]%m;

    int ans = 0;
    for(int l=1; l<=n; ++l)
        ans = (ans + ((n-l+1)*fact[l]%m)*fact[n-l+1]%m)%m;
    cout << ans << endl;
    return 0;
}
