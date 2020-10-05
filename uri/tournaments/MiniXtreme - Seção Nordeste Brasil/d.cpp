#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j)
            cin >> grid[i][j];
    }
    int k;
    cin >> k;
    for(int i=0; i<k; ++i){
        int l, w;
        cin >> l >> w;
    }
    return 0;
}
