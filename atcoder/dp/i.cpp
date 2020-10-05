#include <cpplib/stdinc.hpp>

int n;
vd p;
double dp[(int)3e3][(int)3e3+1];

double solve(int idx, int acc){
    if(idx == n)
        return acc > n/2;
    if(dp[idx][acc] + EPS > 0)
        return dp[idx][acc];
    return dp[idx][acc] = (1-p[idx])*solve(idx+1, acc) + p[idx]*solve(idx+1, acc+1);
}

int32_t main(){
    desync();
    cin >> n;
    p.resize(n);
    for(double &i:p)
        cin >> i;
    for(int i=0; i<n; ++i){
        for(int j=0; j<=n; ++j)
            dp[i][j] = -1;
    }
    cout << fixed << setprecision(15) << solve(0, 0) << endl;
    return 0;
}
