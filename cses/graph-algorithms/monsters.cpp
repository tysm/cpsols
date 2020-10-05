#include <cpplib/stdinc.hpp>

ii next_pos(char dir, ii pos){
    if(dir == 'U')
        pos.ff--;
    else if(dir == 'D')
        pos.ff++;
    else if(dir == 'L')
        pos.ss--;
    else
        pos.ss++;
    return pos;
}

char inv_dir(char dir){
    if(dir == 'U')
        return 'D';
    else if(dir == 'D')
        return 'U';
    else if(dir == 'L')
        return 'R';
    else
        return 'L';
}

int32_t main(){
    // https://cses.fi/problemset/task/1194
    desync();
    int n, m;
    cin >> n >> m;

    ii spos;

    queue<ii> mq;
    vvi dp(n, vi(m));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            char c;
            cin >> c;
            if(c == 'A')
                spos = {i, j};
            else if(c == 'M'){
                mq.push({i, j});
                dp[i][j] = 0;
            }
            else if(c == '#')
                dp[i][j] = -1;
            else
                dp[i][j] = INF;
        }
    }

    while(!mq.empty()){
        ii cur = mq.front(); mq.pop();
        for(char dir:"UDLR"){
            ii pos = next_pos(dir, cur);
            if(pos.ff < 0 or pos.ff >= n or pos.ss < 0 or pos.ss >= m)
                continue;
            if(dp[pos.ff][pos.ss] != INF)
                continue;
            dp[pos.ff][pos.ss] = dp[cur.ff][cur.ss]+1;
            mq.push(pos);
        }
    }

    bool possible = false;
    vector<char> ans;

    char p[n][m] = {}; p[spos.ff][spos.ss] = 1;
    queue<pair<int, ii> > q; q.push({0, spos});
    while(!q.empty()){
        int step = q.front().ff; ii cur = q.front().ss; q.pop();
        if(cur.ff == 0 or cur.ff == n-1 or cur.ss == 0 or cur.ss == m-1){
            possible = true;
            while(cur != spos){
                ans.pb(inv_dir(p[cur.ff][cur.ss]));
                cur = next_pos(p[cur.ff][cur.ss], cur);
            }
            break;
        }
        for(char dir:"UDLR"){
            ii pos = next_pos(dir, cur);
            if(pos.ff < 0 or pos.ff >= n or pos.ss < 0 or pos.ss >= m)
                continue;
            if(dp[pos.ff][pos.ss] <= step+1 or p[pos.ff][pos.ss])
                continue;

            p[pos.ff][pos.ss] = inv_dir(dir);
            q.push({step+1, pos});
        }
    }

    if(!possible)
        cout << "NO" << endl;
    else{
        cout << "YES" << endl << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); ++i)
            cout << ans[i];
        if(ans.size())
            cout << endl;
    }
    return 0;
}
