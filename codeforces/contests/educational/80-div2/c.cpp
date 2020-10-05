#include <cpplib/stdinc.hpp>
#include <cpplib/math/modc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    ModC<> mc;
    cout << mc.C(2*m + n-1, 2*m) << endl; // stars and bars.
    return 0;
}
