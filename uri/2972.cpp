#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    int cnt = __builtin_popcountll(n);
    cout << (1LL<<cnt) << endl;
    return 0;
}
