#include <cpplib/stdinc.hpp>
#include <cpplib/adt/heap.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    queue<ii> B, R;
    vector<string> grid(n);
    for(int i=0; i<n; ++i){
        cin >> grid[i];
        for(int j=0; j<m; ++j){
            if(grid[i][j] == 'B')
                B.ep(i, j);
            else if(grid[i][j] == 'R')
                R.ep(i, j);
        }
    }

    bool ok = true;
    while(!B.empty()){
        auto [i, j] = B.front();
        B.pop();
        if(i-1 >= 0){
            if(grid[i-1][j] == 'R'){
                ok = false;
                break;
            }
            if(grid[i-1][j] == '.'){
                grid[i-1][j] = 'B';
                B.ep(i-1, j);
            }
        }
        if(j-1 >= 0){
            if(grid[i][j-1] == 'R'){
                ok = false;
                break;
            }
            if(grid[i][j-1] == '.'){
                grid[i][j-1] = 'B';
                B.ep(i, j-1);
            }
        }
    }
    while(!R.empty() and ok){
        auto [i, j] = R.front();
        R.pop();
        if(i+1 < n){
            if(grid[i+1][j] == 'B'){
                ok = false;
                break;
            }
            if(grid[i+1][j] == '.'){
                grid[i+1][j] = 'R';
                R.ep(i+1, j);
            }
        }
        if(j+1 < m){
            if(grid[i][j+1] == 'B'){
                ok = false;
                break;
            }
            if(grid[i][j+1] == '.'){
                grid[i][j+1] = 'R';
                R.ep(i, j+1);
            }
        }
    }
    if(!ok){
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    vvi dp(n, vi(m));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(grid[i][j] == '.'){
                dp[i][j]++;
                for(int l=0; l<i; ++l){
                    for(int k=j+1; k<m; ++k){
                        dp[i][j] += dp[l][k];
                    }
                }
                ans += dp[i][j];
            }
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
