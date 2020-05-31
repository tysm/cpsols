#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int a = x2-x1, b = y2-y1;
        cout << a*b + 1 << endl;
    }
    return 0;
}
