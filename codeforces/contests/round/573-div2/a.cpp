#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int r = n%4;
    if(!r)
        cout << 1 << " A" << endl;
    else if(r == 1)
        cout << 0 << " A" << endl;
    else if(r == 2)
        cout << 1 << " B" << endl;
    else if(r == 3)
        cout << 2 << " A" << endl;
    return 0;
}
