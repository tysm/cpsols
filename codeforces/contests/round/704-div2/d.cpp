#include <cpplib/stdinc.hpp>

void solve(){
    int a, b, k;
    cin >> a >> b >> k;

    const int n = a+b;

    vi x(n), y(n);
    rep(i, 0, b)
        x[i] = y[i] = 1;

    if(b > 1 and a > 0){
        swap(y[b-1], y[b-1+min(k, a)]);
        k -= min(a, k);
        for(int i=b-2; k>0 and i>=1; --i, --k)
            swap(y[i], y[i+1]);
    }

    if(k == 0){
        cout << "Yes" << endl;
        rep(i, 0, n)
            cout << x[i];
        cout << endl;
        rep(i, 0, n)
            cout << y[i];
        cout << endl;
    }
    else
        cout << "No" << endl;
}

int32_t main(){
    desync();
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
