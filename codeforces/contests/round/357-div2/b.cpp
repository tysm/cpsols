#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    int a = 1234567;
    int b = 123456;
    int c = 1234;

    bool ok = false;
    for(int i=0; i<=n/a; ++i){
        int l = n - a*i;
        for(int j=0; j<=l/b; ++j){
            int m = l - b*j;
            if(m%c == 0)
                ok = true;
        }
    }
    cout << (ok? "YES" : "NO") << endl;
    return 0;
}
