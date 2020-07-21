#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    cout << (a*x + b*y + c == 0? "YES" : "NO") << endl;
    return 0;
}
