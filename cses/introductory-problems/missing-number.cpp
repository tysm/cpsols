#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1083
    desync();
    int n;
    cin >> n;
    int ans = (n*(n+1))/2;
    for(int i=0; i<n-1; ++i){
        int x;
        cin >> x;
        ans -= x;
    }
    cout << ans << endl;
    return 0;
}
