#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i){
        cout << "Case " << i << ": ";
        int a, b, c;
        cin >> a >> b >> c;
        cout << (c%gcd(a, b)? "No" : "Yes") << endl;
    }
    return 0;
}
