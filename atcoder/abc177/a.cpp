#include <cpplib/stdinc.hpp>
#define double long double

int32_t main(){
    desync();
    int d, t, s;
    cin >> d >> t >> s;
    cout << (s*t >= d? "Yes" : "No") << endl;
    return 0;
}
