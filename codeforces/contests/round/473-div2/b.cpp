#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k, m;
    cin >> n >> k >> m;

    vector<string> arr(n);
    for(string &s:arr)
        cin >> s;

    map<string, int> sti;
    for(int i=0; i<n; ++i)
        sti[arr[i]] = i;

    vi cst(n);
    for(int &i:cst)
        cin >> i;

    vi grp(n), res(k, INF);
    for(int i=0; i<k; ++i){
        int x;
        cin >> x;
        for(int j=0; j<x; ++j){
            int y;
            cin >> y;
            y--;
            grp[y] = i;
            res[i] = min(res[i], cst[y]);
        }
    }

    int ans = 0;
    for(int i=0; i<m; ++i){
        string s;
        cin >> s;
        ans += res[grp[sti[s]]];
    }
    cout << ans << endl;
    return 0;
}
