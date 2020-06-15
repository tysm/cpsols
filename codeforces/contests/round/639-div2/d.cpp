#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    vb wr(n, true), wc(m, true);
    char grid[n][m];
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> grid[i][j];
            if(grid[i][j] == '#')
                wr[i] = wc[j] = false;
        }
    }
    int wr_cnt = 0, wc_cnt = 0;
    for(int i=0; i<n; ++i)
        wr_cnt += wr[i];
    for(int j=0; j<m; ++j)
        wc_cnt += wc[j];
    bool valid = (!wr_cnt and !wc_cnt or wr_cnt and wc_cnt);
    for(int i=0; i<n; ++i){
        int s = 0;
        for(int j=0; j<m; ++j){
            if(grid[i][j] == '.')
                continue;
            if(!j or grid[i][j-1] == '.')
                s++;
        }
        if(s >= 2)
            valid = false;
    }
    for(int j=0; j<m; ++j){
        int s = 0;
        for(int i=0; i<n; ++i){
            if(grid[i][j] == '.')
                continue;
            if(!i or grid[i-1][j] == '.')
                s++;
        }
        if(s >= 2)
            valid = false;
    }
    if(valid){
        int di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0}, ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == '.')
                    continue;
                grid[i][j] = '.';
                ans++;
                queue<ii> q;
                q.push({i, j});
                while(!q.empty()){
                    int l = q.front().ff, k = q.front().ss;
                    q.pop();
                    for(int d=0; d<4; ++d){
                        int li = l + di[d], kj = k + dj[d];
                        if(li < 0 or li >= n)
                            continue;
                        if(kj < 0 or kj >= m)
                            continue;
                        if(grid[li][kj] == '.')
                            continue;
                        grid[li][kj] = '.';
                        q.push({li, kj});
                    }
                }
            }
        }
        cout << ans << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
