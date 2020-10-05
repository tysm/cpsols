#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int a, m;
    cin >> a >> m;
    bool ok = true;
    for(int i=0; i<30; ++i){
        if(a%m == 0)
            ok = false;
        a += a%m;
    }
    cout << (!ok? "Yes" : "No") << endl;
    return 0;
}
