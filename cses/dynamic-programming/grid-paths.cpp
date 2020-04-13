#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1638
    desync();
    int n;
    cin >> n;

    char grid[n][n];
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            cin >> grid[i][j];
    }

    vvi ans(n, vi(n));
    ans[n-1][n-1] = (grid[n-1][n-1] == '.');
    for(int i=n-1; i>=0; --i){
        for(int j=n-1; j>=0; --j){
            if(grid[i][j] == '*')
                continue;

            if(i < n-1)
                ans[i][j] = (ans[i][j] + ans[i+1][j])%M;

            if(j < n-1)
                ans[i][j] = (ans[i][j] + ans[i][j+1])%M;
        }
    }
    cout << ans[0][0] << endl;
    return 0;
}
