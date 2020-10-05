#include <cpplib/stdinc.hpp>

int n, m, x, y;
vi arr;
int dp[1123456][2];

int solve(int idx, int op){
    if(idx == n+1)
        return 0;
    if(dp[idx][op] != -1)
        return dp[idx][op];

    int &res = dp[idx][op];
    res = LINF;

    int j = idx;
    for(int i=idx+1; i<=n+1 and arr[idx]+x >= arr[i]; ++i)
        j = i;
    int aux = LINF;
    while(j > idx){
        aux = 
    }
    if(j != idx){
        while(
        res = min(res, 1+solve(j, 0));
    }

    if(!op){
        for(int i=j+1; i<=n+1 and arr[idx]+y >= arr[i]; ++i)
            j = i;
        if(j != idx)
            res = min(res, 1+solve(j, 1));
    }
    return res;
}

int32_t main(){
    desync();
    cin >> n >> m;

    arr.resize(n+2);
    arr[0] = 1;
    arr[n+1] = m;
    for(int i=1; i<=n; ++i)
        cin >> arr[i];

    cin >> x >> y;

    memset(dp, -1, sizeof(dp));
    int ans = solve(0, 0);
    cout << (ans >= LINF? -1 : ans) << endl;
    return 0;
}
