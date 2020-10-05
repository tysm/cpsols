#include <cpplib/stdinc.hpp>

int n, m;
int di[] = {0, 0, -1, 1, -1, -1, 1, 1}, dj[] = {1, -1, 0, 0, -1, 1, -1, 1};

bool solve(int t, vector<string> &grid, int &ans, vvi &res){
    queue<tt> q;
    vvi cur(n, vi(m, LINF));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(grid[i][j] != 'X')
                continue;
            if(!i or !j or i == n-1 or j == m-1){
                q.ep(i, j, t);
                cur[i][j] = t;
                continue;
            }
            for(int k=0; k<8; ++k){
                int ki = i+di[k], kj = j+dj[k];
                if(ki < 0 or kj < 0 or ki == n or kj == m)
                    continue;
                if(grid[ki][kj] == '.'){
                    q.ep(i, j, t);
                    cur[i][j] = t;
                    break;
                }
            }
        }
    }
    queue<ii> stt;
    vector<string> gen(n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j)
            gen[i] += '.';
    }
    while(!q.empty()){
        int i, j, t;
        tie(i, j, t) = q.front();
        q.pop();

        if(!t){
            stt.ep(i, j);
            gen[i][j] = 'X';
        }

        for(int k=0; k<8; ++k){
            int ki = i+di[k], kj = j+dj[k];
            if(ki < 0 or kj < 0 or ki == n or kj == m)
                continue;
            if(grid[ki][kj] != 'X' or cur[ki][kj] != LINF)
                continue;
            q.ep(ki, kj, t-1);
            cur[ki][kj] = t-1;
        }
    }
    while(!stt.empty()){
        int i = stt.front().ff, j = stt.front().ss;
        stt.pop();
        for(int k=0; k<8; ++k){
            int ki = i+di[k], kj = j+dj[k];
            if(ki < 0 or kj < 0 or ki == n or kj == m)
                continue;
            if(gen[ki][kj] == 'X')
                continue;
            stt.ep(ki, kj);
            gen[ki][kj] = 'X';
        }
    }
    for(int i=0; i<n; ++i)
        debug(cur[i]);
    bool ok = true;
    for(int i=0; i<n; ++i)
        ok &= (gen[i] == grid[i]);
    if(ok){
        ans = t;
        res = cur;
    }
    return ok;
}

int32_t main(){
    desync();
    cin >> n >> m;

    vector<string> grid(n);
    for(string &s:grid)
        cin >> s;

    int lo = 0, hi = max(m, n), ans = 0;
    vvi res(n, vi(m));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j)
            res[i][j] = (grid[i][j] == '.')*LINF;
    }
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(solve(mid, grid, ans, res))
            lo = mid+1;
        else
            hi = mid-1;
    }
    cout << ans << endl;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j)
            cout << (!res[i][j]? 'X' : '.');
        cout << endl;
    }
    return 0;
}
