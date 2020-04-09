#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1754
    desync();
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        // a = 2*x + y
        // b = 2*y + x
        // y = a - 2*x
        // b = 2*a - 3*x
        // x = (2*a - b)/3
        // y = (2*b - a)/3
        if((2*a - b)%3 == 0 and (2*b - a)%3 == 0){
            int x = (2*a - b)/3, y = (2*b - a)/3;
            if(x >= 0 and y >= 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
