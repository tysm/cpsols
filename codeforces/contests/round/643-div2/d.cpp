#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, s;
    cin >> n >> s;
    if(s >= 2*n){
        cout << "YES" << endl;
        for(int i=0; i<n-1; ++i)
            cout << 2 << ' ';
        cout << s - 2*(n-1) << endl << 1 << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
