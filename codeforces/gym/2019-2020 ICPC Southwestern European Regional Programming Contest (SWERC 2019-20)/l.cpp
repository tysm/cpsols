#include <cpplib/stdinc.hpp>

int n;
vector<string> grid;
vvi vis;

vector<set<ii> > shores(100);

int di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0};

void dfs1(int i, int j, int id){
    vis[i][j] = -1;
    for(int k=0; k<4; ++k){
        int ki = i+di[k], kj = j+dj[k];
        if(ki < 0 or kj < 0 or ki >= n or kj >= n)
            continue;
        if(vis[ki][kj] != -2)
            continue;
        if(grid[ki][kj] == 'x')
            continue;
        if(grid[ki][kj] == '.')
            vis[ki][kj] = id;
        else
            dfs1(ki, kj, id);
    }
}

void dfs2(int i, int j, int id){
    int val = vis[i][j];

    vis[i][j] = -1;
    shores[id].ep(i, j);
    for(int k=0; k<4; ++k){
        int ki = i+di[k], kj = j+dj[k];
        if(ki < 0 or kj < 0 or ki >= n or kj >= n)
            continue;
        if(vis[ki][kj] == val)
            dfs2(ki, kj, id);
    }
}

map<vvb, int> dp;
int grundy(set<ii> &shore, vvb &state, int cnt){
    if(cnt == shore.size())
        return 0;
    if(dp.count(state))
        return dp[state];

    unordered_set<int> seen;
    for(auto [i, j] : shore){
        if(state[i][j])
            continue;
        vii cur;
        cur.eb(i, j);

        state[i][j] = true;
        for(int k=0; k<4; ++k){
            int ki = i+di[k], kj = j+dj[k];
            if(ki < 0 or kj < 0 or ki >= n or kj >= n)
                continue;
            if(shore.count(ii(ki, kj)) and !state[ki][kj]){
                cur.eb(ki, kj);
                state[ki][kj] = true;
            }
        }
        seen.ep(grundy(shore, state, cnt + cur.size()));
        for(auto [ki, kj] : cur)
            state[ki][kj] = false;
    }
    int mex = 0;
    while(seen.count(mex))
        mex++;
    return dp[state] = mex;
}

int32_t main(){
    desync();
    cin >> n;

    grid.resize(n);
    for(string &s:grid)
        cin >> s;

    int id = 0;
    vis.resize(n, vi(n, -2));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(grid[i][j] == '*' and vis[i][j] == -2)
                dfs1(i, j, id++);
        }
    }

    id = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(vis[i][j] >= 0)
                dfs2(i, j, id++);
        }
    }

    int ans = 0;
    for(int i=0; i<id; ++i){
        vvb state(n, vb(n));
        dp.clear();
        ans ^= grundy(shores[i], state, 0);
    }
    cout << (ans? "First" : "Second") << " player will win" << endl;
    return 0;
}
