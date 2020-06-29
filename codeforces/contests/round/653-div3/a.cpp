#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int x, y, n;
        cin >> x >> y >> n;
        int v = (n/x)*x + y;
        if(v > n)
            v -= x;
        cout << v << endl;
    }
    return 0;
}
