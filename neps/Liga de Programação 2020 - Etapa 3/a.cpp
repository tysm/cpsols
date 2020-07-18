#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int k, x, y;
    cin >> k >> x >> y;
    cout << (abs(x-y) >= k? "EH SUFICIENTE" : "NAO EH SUFICIENTE") << endl;
    return 0;
}
