#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int v, e;
        cin >> v >> e;
        cout << 2 - (v - e) << endl;
    }
    return 0;
}
