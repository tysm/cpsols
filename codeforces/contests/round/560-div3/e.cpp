#include <cpplib/stdinc.hpp>
#undef MOD
#define MOD 998244353
#include <cpplib/adt/modular.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi a(n);
    for(int i=1; i<=n; ++i){
        cin >> a[i-1];
        a[i-1] *= i*(n-i+1);
    }
    vi b(n);
    for(int &i:b)
        cin >> i;
    sort(all(a));
    sort(rall(b));
    mint ans;
    for(int i=0; i<n; ++i)
        ans += (mint)a[i]*b[i];
    cout << ans << endl;
    return 0;
}
