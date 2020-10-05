#include <cpplib/stdinc.hpp>
#include <cpplib/math/combinatorics/fibonacci-number.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1722
    desync();
    int n;
    cin >> n;
    cout << fibm(n).ff << endl;
    return 0;
}
