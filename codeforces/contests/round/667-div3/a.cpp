#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << (abs(a-b)/10 + (abs(a-b)%10 > 0)) << endl;
    }
    return 0;
}
