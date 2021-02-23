#include <cpplib/stdinc.hpp>

void solve(){
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vi l(m, -1), r(m, -1);
    for(int i=0, j=0; i<n and j<m; ++i){
        if(s[i] == t[j]){
            l[j] = i;
            j++;
        }
    }
    for(int i=n-1, j=m-1; i>=0 and j>=0; --i){
        if(s[i] == t[j]){
            r[j] = i;
            j--;
        }
    }

    int ans = 0;
    rep(i, 1, m)
        ans = max(ans, r[i]-l[i-1]);
    cout << ans << endl;
}

int32_t main(){
    desync();
    int t=1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
