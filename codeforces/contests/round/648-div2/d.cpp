#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    int di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0};
    while(t--){
        int n, m;
        cin >> n >> m;

        char grid[n][m];
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j)
                cin >> grid[i][j];
        }

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] != 'B')
                    continue;

                for(int k=0; k<4; ++k){
                    int ki = i+di[k], kj = j+dj[k];
                    if(ki < 0 or ki >= n)
                        continue;
                    if(kj < 0 or kj >= m)
                        continue;

                    if(grid[ki][kj] != '.')
                        continue;

                    grid[ki][kj] = '#';
                }
            }
        }

        bool dp[n][m] = {};
        queue<ii> q;
        if(grid[n-1][m-1] != '#'){
            dp[n-1][m-1] = true;
            q.push({n-1, m-1});
        }
        while(!q.empty()){
            int i = q.front().ff, j = q.front().ss;
            q.pop();
            for(int k=0; k<4; ++k){
                int ki = i+di[k], kj = j+dj[k];
                if(ki < 0 or ki >= n)
                    continue;
                if(kj < 0 or kj >= m)
                    continue;
                if(grid[ki][kj] == '#')
                    continue;

                if(dp[ki][kj])
                    continue;
                dp[ki][kj] = true;
                q.push({ki, kj});
            }
        }
        bool valid = true;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == 'B' and dp[i][j])
                    valid = false;
                if(grid[i][j] == 'G' and !dp[i][j])
                    valid = false;
            }
        }
        if(valid)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
