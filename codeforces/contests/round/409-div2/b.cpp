#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    string x, z;
    cin >> x >> z;

    int n = x.size();
    bool ok = true;
    for(int i=0; i<n; ++i){
        if(z[i] > x[i])
            ok = false;
    }
    if(ok)
        cout << z << endl;
    else
        cout << -1 << endl;

    return 0;
}
