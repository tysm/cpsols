#include <cpplib/stdinc.hpp>

int n;
int psum[5001];
int dp[5001][5001];
bool vis[5001][5001];

int sum(int i, int j){
    int ans = psum[j];
    if(i)
        ans -= psum[i-1];
    return ans;
}

int solve(int i, int j){
    if(vis[i][j])
        return dp[i][j];
    int op1 = dp[i][i] + sum(i+1, j) - solve(i+1, j);
    int op2 = dp[j][j] + sum(i, j-1) - solve(i, j-1);
    vis[i][j] = true;
    return dp[i][j] = max(op1, op2);
}

int32_t main(){
    // https://cses.fi/problemset/task/1097
    desync();
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> dp[i][i];
        psum[i] = dp[i][i];
        if(i)
            psum[i] += psum[i-1];
        vis[i][i] = true;
    }
    cout << solve(0, n-1) << endl;
    return 0;
}
