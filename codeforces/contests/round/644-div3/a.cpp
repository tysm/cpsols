#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << min(max(a, b+b), max(b, a+a))*min(max(a, b+b), max(b, a+a)) << endl;
    }
    return 0;
}
