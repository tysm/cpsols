#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1068
    desync();
    int n;
    cin >> n;
    while(n != 1){
        cout << n << ' ';
        n = (n%2? n*3+1 : n/2);
    }
    cout << n << endl;
    return 0;
}
