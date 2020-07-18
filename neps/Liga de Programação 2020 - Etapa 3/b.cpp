#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int acc = 0, ans = 0;
    for(int d:to_string(n)){
        d -= '0';
        int aux = abs(d - acc);
        ans += min(aux, 10-aux);
        acc = d;
    }
    cout << ans << endl;
    return 0;
}
