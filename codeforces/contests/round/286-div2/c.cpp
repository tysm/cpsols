#include <cpplib/stdinc.hpp>

int n;
vi arr(30001);
map<int, int> dpm[30001];
int dp[30001][700];

int solve(int idx, int l){
    if(idx >= 30001)
        return 0;
    if(l >= 700){
        if(dpm[idx].count(l))
            return dpm[idx][l];
    }
    else{
        if(dp[idx][l] != -1)
            return dp[idx][l];
    }
    int res = 0;
    for(int i=-1; i<=1; ++i){
        if(idx+l+i > idx)
            res = max(res, solve(idx+l+i, l+i));
    }
    res += arr[idx];
    if(l >= 700)
        return dpm[idx][l] = res;
    return dp[idx][l] = res;
}

int32_t main(){
    desync();
    int d;
    cin >> n >> d;

    memset(dp, -1, sizeof(dp));

    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        arr[x]++;
    }

    cout << solve(d, d) << endl;
    return 0;
}
