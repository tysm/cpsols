#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi ans;
    for(int i=1; i<=n; i+=2){
        ans.pb(i);
        if(i != n)
            ans.pb(2*n-i+1);
    }
    for(int i=2; i<=n+1; i+=2){
        ans.pb(i);
        if(i != n+1)
            ans.pb(2*n-i+1);
    }
    if(n%2){
        cout << "YES" << endl;
        for(int i=0; i<2*n; ++i){
            if(i)
                cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
