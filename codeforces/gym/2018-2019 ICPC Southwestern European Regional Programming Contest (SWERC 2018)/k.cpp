#include <cpplib/stdinc.hpp>
#include <cpplib/string/z-function.hpp>

int n;
string s;

int dp[700][700];

int kstring(const string &s){
    vi z = z_function(s);
    for(int i=1; i<s.size(); ++i){
        if(z[i] == s.size()-i and s.size()%i == 0)
            return i;
    }
    return 0;
}

int solve(int l, int r){
    if(l == r)
        return 1;
    int &res = dp[l][r];
    if(res == -1){
        int k = kstring(s.substr(l, r-l+1));
        if(k)
            res = solve(l, l+k-1);
        else{
            res = INF;
            for(int mid=l; mid<r; ++mid){
                int a = solve(l, mid), b = solve(mid+1, r);
                res = min(res, a+b);
            }
        }
    }
    return res;
}

int32_t main(){
    desync();
    cin >> n >> s;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n-1) << endl;
    return 0;
}
