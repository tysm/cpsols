#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    cout << (2*n+k-1)/k + (5*n+k-1)/k + (8*n+k-1)/k << endl;
    return 0;
}
