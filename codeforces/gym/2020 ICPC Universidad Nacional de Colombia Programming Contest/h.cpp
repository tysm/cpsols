#include <cpplib/stdinc.hpp>
#include <cpplib/adt/rolling-hash.hpp>

int res = 0;

set<ii> vis;
void manacher(const string &s, RollingHash &hsh)
{
    int n = s.size();
    pair<int, int> ans = {0, 0};
    vector<int> dp(n);
    for(int i = 0, l = 0, r = 0; i < n; ++i) {
        int k = (i > r ? 1 : min(dp[l + r - i] + 1, r - i + 1));
        while(i - k >= 0 and i + k < n and s[i - k] == s[i + k])
            k++;
        dp[i] = --k;
        if(i + k > r) {
            l = i - k;
            r = i + k;
            if(r - l > ans.second - ans.first)
                ans = {l, r};
        }
    }

    vii idx(n);
    for(int i=0; i<n; ++i){
        idx[i].ff = dp[i];
        idx[i].ss = i;
    }
    sort(rall(idx));

    for(auto [d, i]:idx){
        for(int j=d; j>=1; j--){
            auto qr = hsh.query(i-j, i+j);
            if(vis.count(qr))
                break;
            vis.ep(qr);
            res++;
        }
    }
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    string s;
    cin >> s;

    RollingHash hsh(s, 29, 'a');

    manacher(s, hsh);
    cout << res << endl;
    return 0;
}
