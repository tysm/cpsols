#include <cpplib/stdinc.hpp>

void solve(){
    int n;
    cin >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    vi ans, vis(n+1);
    int cur = n, r = n;
    for(int i=n-1; i>=0; --i){
        vis[arr[i]] = true;

        if(arr[i] != cur)
            continue;

        for(int l=i; l<r; ++l)
            ans.eb(arr[l]);
        r = i;

        while(vis[cur])
            cur--;
    }
    cout << ans << endl;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
