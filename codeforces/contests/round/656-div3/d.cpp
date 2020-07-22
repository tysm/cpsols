#include <cpplib/stdinc.hpp>

int solve(string &s, char c, int l, int r){
    if(l == r)
        return s[l] != c;
    int res1 = 0;
    for(int i=l; i<=(l+r)/2; ++i)
        res1 += (s[i] != c);
    res1 += solve(s, c+1, (l+r)/2+1, r);
    int res2 = 0;
    for(int i=(l+r)/2+1; i<=r; ++i)
        res2 += (s[i] != c);
    res2 += solve(s, c+1, l, (l+r)/2);
    return min(res1, res2);
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s, 'a', 0, n-1) << endl;
    }
    return 0;
}
