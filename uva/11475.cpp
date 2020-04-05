#include <cpplib/stdinc.hpp>

ii manacher(const string &s){
    int n = s.size();

    ii ans = {n-1, n-1};
    vi dp(n);
    for(int i=0, l=0, r=0; i<n; ++i){
        int k = (i > r? 1 : min(dp[l + r - i] + 1, r - i + 1));
        while(i - k >= 0 and i + k < n and s[i - k] == s[i + k])
            k++;
        dp[i] = --k;
        int li = i - k, ri = i + k;
        if(i + k > r){
            l = li;
            r = ri;
        }
        if(ri == n-1 and ri - li > ans.ss - ans.ff)
            ans = {li, ri};
    }
    dp.assign(n, 0);
    for(int i=0, l=0, r=0; i<n; ++i){
        int k = (i > r? 0 : min(dp[l + r - i + 1] + 1, r - i + 1));
        while(i - k - 1 >= 0 and i + k < n and s[i - k - 1] == s[i + k])
            k++;
        dp[i] = --k;
        int li = i - k - 1, ri = i + k;
        if(i + k > r){
            l = li;
            r = ri;
        }
        if(ri == n-1 and ri - li > ans.ss - ans.ff)
            ans = {li, ri};
    }
    return ans;
}

int32_t main(){
    desync();
    string s;
    while(cin >> s){
        ii bounds = manacher(s);
        while(bounds.ff > 0)
            s += s[--bounds.ff];
        cout << s << endl;
    }
    return 0;
}
