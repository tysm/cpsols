#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int ans = 2*n + 2;
    for(int i=1; i<n; ++i){
        if(n%i == 0)
            ans = min(ans, 2*i + 2*(n/i));
    }
    cout << ans << endl;
    return 0;
}
