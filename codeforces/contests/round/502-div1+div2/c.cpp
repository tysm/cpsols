#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    int ans = -1, cur = LINF;
    for(int i=1; i<=n; ++i){
        int v = i + n/i + (n%i != 0);
        if(v < cur){
            ans = i;
            cur = v;
        }
    }
    vi res;
    for(int i=n; i>0; i-=ans){
        for(int j=max((int)1, i-ans+1); j<=i; ++j)
            res.eb(j);
    }
    cout << res << endl;
    return 0;
}
