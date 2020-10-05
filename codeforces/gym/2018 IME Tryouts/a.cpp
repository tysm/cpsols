#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/modular.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    if(n & 1)
        cout << 0 << endl;
    else{
        mint acc, ans = 1;
        for(int i=2; i<=n; i+=2){
            mint aux = ans;
            ans = ans*3 + acc;
            acc += aux*2;
        }
        cout << ans << endl;
    }
    return 0;
}
