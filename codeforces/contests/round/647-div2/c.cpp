#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << 2*n - __builtin_popcountll(n) << endl;
    }
    return 0;
}
