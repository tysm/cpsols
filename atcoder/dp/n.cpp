#include <cpplib/stdinc.hpp>

int n;
vi arr;
pair<int, int> dp[(int)4e2][(int)4e2];

pair<int, int> solve(int i, int j){
    if(i == j)
        return {arr[i], 0};
    pair<int, int> &res = dp[i][j];
    if(res.ss == -1){
        for(int k=i; k<j; ++k){
            ii a = solve(i, k), b = solve(k+1, j);
            int cost = a.ss + b.ss + a.ff + b.ff;
            if(res.ss == -1 or cost < res.ss)
                res = {a.ff + b.ff, cost};
            else if(cost == res.ss)
                res.ff = min(res.ff, a.ff + b.ff);
        }
    }
    return res;
}

int32_t main(){
    desync();
    cin >> n;
    arr.resize(n);
    for(int &i:arr)
        cin >> i;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            dp[i][j] = {-1, -1};
        }
    }
    cout << solve(0, n-1).ss << endl;
    return 0;
}
