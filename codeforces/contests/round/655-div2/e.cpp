#include <cpplib/stdinc.hpp>

int n, m, dp[112][112], lft[112][112], rgt[112][112];

int solve(int l, int r){
    if(l > r)
        return 0;
    int &res = dp[l][r];
    if(res == -1){
        res = 0;
        for(int k=l; k<=r; ++k){
            int cnt = 0;
            for(int i=0; i<n; ++i)
                cnt += (lft[i][k] >= l and rgt[i][k] <= r);
            res = max(res, cnt*cnt + solve(l, k-1) + solve(k+1, r));
        }
    }
    return res;
}

int32_t main(){
    desync();
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        int k;
        cin >> k;
        while(k--){
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            for(int j=l; j<=r; ++j){
                lft[i][j] = l;
                rgt[i][j] = r;
            }
        }
    }
    cout << solve(0, m-1) << endl;
    return 0;
}
