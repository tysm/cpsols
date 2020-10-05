#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << n/5 + (n%5 != 0) << endl;
    }
    return 0;
}
