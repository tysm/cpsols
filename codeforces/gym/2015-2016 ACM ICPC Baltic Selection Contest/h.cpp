#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    cout << n*m + min(n, m) << endl;
    return 0;
}
