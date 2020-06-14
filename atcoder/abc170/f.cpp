#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m, k;
    cin >> n >> m >> k;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;

    vvi ans(n, vi(m, INF)), cnt(n, vi(m));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            char c;
            cin >> c;
            if(c == '@')
                ans[i][j] = -1;
        }
    }
    ans[x1][y1] = 0;
    cnt[x1][y1] = 1;
    queue<ii> q;
    q.push({x1, y1});
    while(!q.empty()){
        int x = q.front().ff, y = q.front().ss;
        q.pop();

        // right
        for(int i=1; i<=k and y+i<m and ans[x][y+i] >= ans[x][y] and cnt[x][y+i] < 4; ++i){
            cnt[x][y+i]++;
            ans[x][y+i] = min(ans[x][y+i], ans[x][y]+1);
            q.push({x, y+i});
        }

        // left
        for(int i=1; i<=k and y-i>=0 and ans[x][y-i] >= ans[x][y]+1  and cnt[x][y-i] < 4; ++i){
            cnt[x][y-i]++;
            ans[x][y-i] = min(ans[x][y-i], ans[x][y]+1);
            q.push({x, y-i});
        }

        // down
        for(int i=1; i<=k and x+i<n and ans[x+i][y] >= ans[x][y]+1 and cnt[x+i][y] < 4; ++i){
            cnt[x+i][y]++;
            ans[x+i][y] = min(ans[x+i][y], ans[x][y]+1);
            q.push({x+i, y});
        }

        // up
        for(int i=1; i<=k and x-i>=0 and ans[x-i][y] >= ans[x][y]+1 and cnt[x-i][y] < 4; ++i){
            cnt[x-i][y]++;
            ans[x-i][y] = min(ans[x-i][y], ans[x][y]+1);
            q.push({x-i, y});
        }
    }
    cout << (ans[x2][y2] == INF? -1 : ans[x2][y2]) << endl;
    return 0;
}
