#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(n == 1 or m == 1)
            cout << "YES" << endl;
        else if(n == 2 and m == 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
