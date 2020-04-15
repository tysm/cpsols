#include <cpplib/stdinc.hpp>

void dfs(vector<string> &arr, int i, int j){
    arr[i][j] = 0;
    int di[4] = {-1, 0, 0, 1}, dj[4] = {0, -1, 1, 0};
    for(int k=0; k<4; ++k){
        if(i+di[k] < 0 or i+di[k] >= arr.size())
            continue;
        if(j+dj[k] < 0 or j+dj[k] >= arr[0].size())
            continue;
        if(arr[i+di[k]][j+dj[k]] == '.')
            dfs(arr, i+di[k], j+dj[k]);
    }
}

int32_t main(){
    // https://cses.fi/problemset/task/1192
    desync();
    int n, m, ans = 0;
    cin >> n >> m;
    vector<string> arr(n);
    for(string &s:arr)
        cin >> s;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(arr[i][j] == '.'){
                dfs(arr, i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
