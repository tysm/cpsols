#include <cpplib/stdinc.hpp>

bool vis[int32_t(1e5)][10];
int dp[int32_t(1e5)][10];

int solve(string &s, string &p, int i, int j){
    if(j == p.size())
        return true;
    else if(i == s.size())
        return false;
    else if(vis[i][j])
        return dp[i][j];

    int ans = solve(s, p, i+1, j);
    if(s[i] == p[j])
        ans = (ans + solve(s, p, i+1, j+1))%M;
    vis[i][j] = true;
    return dp[i][j] = ans;
}

int32_t main(){
    desync();
    string s, p;
    cin >> s >> p;
    cout << solve(s, p, 0, 0) << endl;
    return 0;
}
