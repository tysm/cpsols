#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();

    int ans = INF;
    for(int i=0; i+m-1<n; ++i){
        int acc = 0;
        for(int j=0; j<m; ++j)
            acc += (s[i+j] != t[j]);
        ans = min(ans, acc);
    }
    cout << ans << endl;
    return 0;
}
