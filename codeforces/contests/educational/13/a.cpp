#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    cout << (n/k)*k + k << endl;
    return 0;
}
