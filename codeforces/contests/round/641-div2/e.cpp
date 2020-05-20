#include <cpplib/stdinc.hpp>

int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};

int32_t main(){
    desync();
    int n, m, t;
    cin >> n >> m >> t;

    vector<string> grid(n);
    for(int i=0; i<n; ++i)
        cin >> grid[i];

    queue<ii> q;
    int dp[n][m];
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            int b = 0, w = 0;
            for(int k=0; k<4; ++k){
                int ik = i+di[k], jk = j+dj[k];
                if(ik < 0 or ik >= n or jk < 0 or jk >= m)
                    continue;
                if(grid[ik][jk] == '0')
                    w++;
                else
                    b++;
            }
            if(grid[i][j] == '0' and w or grid[i][j] == '1' and b){
                dp[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        int i = q.front().ff, j = q.front().ss; q.pop();
        for(int k=0; k<4; ++k){
            int ik = i+di[k], jk = j+dj[k];
            if(ik < 0 or ik >= n or jk < 0 or jk >= m)
                continue;
            if(dp[ik][jk] != -1)
                continue;
            dp[ik][jk] = dp[i][j]+1;
            q.push({ik, jk});
        }
    }

    while(t--){
        int i, j, k;
        cin >> i >> j >> k;
        i--; j--;
        if(dp[i][j] == -1 or k <= dp[i][j])
            cout << grid[i][j] << endl;
        else{
            k -= dp[i][j];
            cout << (grid[i][j]-'0'+(k%2))%2 << endl;
        }
    }
    return 0;
}
