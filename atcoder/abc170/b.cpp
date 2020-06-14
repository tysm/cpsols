#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int x, y;
    cin >> x >> y;
    bool valid = false;
    for(int i=0; i<=x; ++i){
        if(i*2 + (x-i)*4 == y)
            valid = true;
    }
    if(valid)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
