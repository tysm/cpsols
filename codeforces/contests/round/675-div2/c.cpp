#include <cpplib/stdinc.hpp>
#include <cpplib/adt/modular.hpp>
#include <cpplib/math/modc.hpp>

int32_t main(){
    desync();
    ModC<> comp();

    int n;
    string s;
    cin >> s;
    n = s.size();

    mint ans = 0;
    for(int i=0; i<n; ++i)
        ans += mint(i+1)*mint(n-i)*mint((int)(s[i]-'0'));
    cout << ans << endl;
    return 0;
}
