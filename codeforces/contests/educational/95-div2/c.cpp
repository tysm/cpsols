#include <cpplib/stdinc.hpp>

int n;
vi dp[2], arr;

int solve(int idx, int k){
    if(idx >= n)
        return 0;

    int &res = dp[k][idx];
    if(res == -1){
        res = (k? 0 : arr[idx]) + solve(idx+1, k^1);
        if(idx+1 < n)
            res = min(res, (k? 0 : arr[idx]+arr[idx+1]) + solve(idx+2, k^1));
    }
    return res;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        cin >> n;

        arr.resize(n);
        for(int &i:arr)
            cin >> i;

        dp[0].assign(n, -1);
        dp[1].assign(n, -1);
        cout << solve(0, 0) << endl;
    }
    return 0;
}
