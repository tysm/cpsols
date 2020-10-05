#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi dg(n+1);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        dg[a]++;
        dg[b]++;
    }
    bool ok = true;
    for(int i:dg)
        ok &= (i != 2);
    cout << (ok? "YES" : "NO") << endl;
    return 0;
}
