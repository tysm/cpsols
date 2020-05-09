#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int r = k%(n-1), m = (k-1)/(n-1);
        if(r == 0)
            r = n-1;
        // debug(n);
        // debug(k);
        // debug(r);
        // debug(m);
        cout << m*n+r << endl;
    }
    return 0;
}
