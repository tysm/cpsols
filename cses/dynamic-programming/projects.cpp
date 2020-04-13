#include <cpplib/stdinc.hpp>

int n;
vector<pair<ii, int> > v;

int dp[MAX];

int solve(int idx){
    if(idx >= n)
        return 0;
    if(dp[idx])
        return dp[idx];

    int op1 = solve(idx+1);
    int op2 = v[idx].ss;
    int jdx = upper_bound(v.begin(), v.end(), pair<ii, int>({{v[idx].ff.ss+1, 0}, 0})) - v.begin();
    op2 += solve(jdx);
    return dp[idx] = max(op1, op2);
}

int32_t main(){
    // https://cses.fi/problemset/task/1140
    desync();
    cin >> n;
    for(int i=0; i<n; ++i){
        int a, b, p;
        cin >> a >> b >> p;
        v.pb({{a, b}, p});
    }
    sort(v.begin(), v.end());
    cout << solve(0) << endl;
    return 0;
}
