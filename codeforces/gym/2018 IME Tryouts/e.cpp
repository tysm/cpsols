#include <cpplib/stdinc.hpp>
#include <cpplib/math/gauss.hpp>
#include <cpplib/math/euclid.hpp>

int32_t main(){
    desync();
    int d[3], h;
    cin >> d[0] >> d[1] >> d[2] >> h;
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    string A = "RNE", B = "ABC";
    vi dmg(n);
    for(int l=0; l<3; ++l){
        vi a(2*n), b(2*n);
        for(int i=0; i<2*n; ++i)
            a[i] = (s[i%n] == A[l]);
        for(int i=0; i<m; ++i)
            b[m-i-1] = (t[i] == B[l]);
        vi r = multiply(a, b);
        for(int i=n-1; i<2*n-1; ++i)
            dmg[i%n] += d[l]*r[i];
    }
    int a = 0, b = n;
    for(int i:dmg)
        a += (i >= h);
    int g = gcd(a, b);
    cout << a/g << ' ' << b/g << endl;
    return 0;
}
