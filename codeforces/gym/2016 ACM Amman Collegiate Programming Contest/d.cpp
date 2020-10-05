#include <cpplib/stdinc.hpp>

int solve(vi &cur){
    vi dp(cur.size());
    stack<int> s;
    for(int i=0; i<cur.size(); ++i){
        while(!s.empty() and cur[s.top()] >= cur[i])
            s.pop();
        int lst = s.empty()? -1 : s.top();
        int ret = (i-lst)*cur[i];
        int lft = s.empty()? 0 : dp[lst];
        dp[i] = ret + lft;
        s.emplace(i);
    }
    return accumulate(all(dp), 0LL);
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vvi grid(n, vi(m));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j)
                cin >> grid[i][j];
        }

        vvi up(n, vi(m, 1));
        for(int i=1; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == grid[i-1][j])
                    up[i][j] += up[i-1][j];
            }
        }

        int ans = 0;
        for(int i=0; i<n; ++i){
            vi cur;
            for(int j=0; j<m; ++j){
                if(j and grid[i][j] != grid[i][j-1]){
                    ans += solve(cur);
                    cur.clear();
                }
                cur.eb(up[i][j]);
            }
            ans += solve(cur);
        }
        cout << ans << endl;
    }
    return 0;
}
