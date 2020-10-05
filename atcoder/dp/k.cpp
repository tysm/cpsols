#include <cpplib/stdinc.hpp>

int dp[2][(int)1e5+1];

int solve(vi &arr, int acc, int cur){
    int &res = dp[cur][acc];
    if(res == -1){
        res = cur;
        for(int i:arr){
            if(acc-i >= 0 and solve(arr, acc-i, !cur) == !cur)
                res = !cur;
        }
    }
    return res;
}

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    memset(dp, -1, sizeof(dp));
    if(solve(arr, k, 0))
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    return 0;
}
