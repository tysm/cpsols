#include <cpplib/stdinc.hpp>

int dp[2][(int)3e3][(int)3e3];
bool dp_aux[2][(int)3e3][(int)3e3];
vi arr;

int solve(int i, int j, int cur){
    if(j < i)
        return 0;
    if(dp_aux[cur][i][j])
        return dp[cur][i][j];
    dp_aux[cur][i][j] = true;
    if(cur == 0){
        return dp[cur][i][j] = max(
            arr[i] + solve(i+1, j, 1),
            arr[j] + solve(i, j-1, 1)
        );
    }
    else{
        return dp[cur][i][j] = min(
            - arr[i] + solve(i+1, j, 0),
            - arr[j] + solve(i, j-1, 0)
        );
    }
}

int32_t main(){
    desync();
    int n;
    cin >> n;
    arr.resize(n);
    for(int &i:arr)
        cin >> i;
    cout << solve(0, n-1, 0) << endl;
    return 0;
}
