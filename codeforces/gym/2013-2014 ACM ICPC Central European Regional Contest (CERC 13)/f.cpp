#include <cpplib/stdinc.hpp>

map<vector<string>, int> dp[100];

int di[] = {-1, -1, 1, 1}, dj[] = {-1, 1, -1, 1};

int solve(int i, int j, int idx, vector<string> &grid){
    if(dp[idx].count(grid))
        return dp[i*10+j][grid];
    grid[i][j] = '#';
    int res = 0;
    for(int k=0; k<4; ++k){
        int ki = 2*di[k] + i, kj = 2*dj[k] + j;
        if(ki < 0 or kj < 0 or ki >= 10 or kj >= 10)
            continue;
        if(grid[ki][kj] != '#')
            continue;
        int bi = di[k]+i, bj = dj[k]+j;
        if(grid[bi][bj] != 'B')
            continue;
        grid[ki][kj] = 'W';
        grid[bi][bj] = '#';
        res = max(res, 1+solve(ki, kj, idx, grid));
        grid[ki][kj] = '#';
        grid[bi][bj] = 'B';
    }
    grid[i][j] = 'W';
    return dp[idx][grid] = res;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        for(int i=0; i<100; ++i)
            dp[i].clear();
        vector<string> grid(10);
        for(int i=0; i<10; ++i)
            cin >> grid[i];
        int ans = 0;
        for(int i=0; i<10; ++i){
            for(int j=0; j<10; ++j){
                if(grid[i][j] != 'W')
                    continue;
                ans = max(ans, solve(i, j, i*10+j, grid));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
