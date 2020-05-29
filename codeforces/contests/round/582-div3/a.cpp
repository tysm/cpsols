#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int ans = 0;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        ans += (x%2);
    }
    cout << min(ans, n-ans) << endl;
    return 0;
}
