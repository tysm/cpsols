#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        cout << (a < c? 1 : -1) << ' ' << (a*b <= c? -1 : b) << endl;
    }
    return 0;
}
