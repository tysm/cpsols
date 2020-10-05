#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/exponentiation.hpp>
#include <cpplib/math/combinatorics/combinatorics.hpp>

int32_t main(){
    desync();
    string m;
    cin >> m;
    uint n = m.size(), ans = 0;
    for(uint i=0; i<n; ++i){
        uint j = m[i] - '0';
        if(!j)
            continue;
        uint d = n-(i+1), t = exp((uint)10, d);
        if(j == 1 or j == 7){
            if(i == n-1)
                ans++;
            else
                ans += stoll(m.substr(i+1))+1;
        }
        if(j > 1)
            ans += t;
        if(j > 7)
            ans += t;
        for(uint k=0; k<d; ++k)
            ans += j*C(d, k)*exp((uint)2, d-k)*exp((uint)8, k)*(d-k);
    }
    cout << ans << endl;
    return 0;
}
