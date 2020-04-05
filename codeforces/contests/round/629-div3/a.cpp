#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a%b == 0)
            cout << 0 << endl;
        else
            cout << b-(a%b) << endl;
    }
    return 0;
}
