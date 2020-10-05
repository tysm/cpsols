#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        int lo = min(n, 1+max((int)0, (x+y)-n));
        int hi = min(n, x+y-1);
        cout << lo << ' ' << hi << endl;
    }
    return 0;
}
