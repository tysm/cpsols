#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1072
    desync();
    int n;
    cin >> n;
    for(int k=1; k<=n; ++k){
        int k2 = k*k;
        cout << (k2*(k2-1))/2 - 4*(k-2)*(k-1) << endl;
    }
    return 0;
}
