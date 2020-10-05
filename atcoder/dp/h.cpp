#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(string &s:grid)
        cin >> s;
    vvi ans(n, vi(m));
    ans[0][0] = (grid[0][0] != '#');
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(!i and !j or grid[i][j] == '#')
                continue;
            if(i)
                ans[i][j] += ans[i-1][j];
            if(j)
                ans[i][j] += ans[i][j-1];
            ans[i][j] = mod(ans[i][j]);
        }
    }
    cout << ans[n-1][m-1] << endl;
    return 0;
}
