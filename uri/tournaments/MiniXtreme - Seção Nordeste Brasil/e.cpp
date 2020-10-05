#include <cpplib/stdinc.hpp>

int activate(char c, int k){
    if(c == 'p')
        k |= (1<<0);
    if(c == 't')
        k |= (1<<1);
    if(c == 'm')
        k |= (1<<2);
    if(c == 'e')
        k |= (1<<3);
    if(c == 'r')
        k |= (1<<4);
    if(c == 'a')
        k |= (1<<5);
    if(c == 'b')
        k |= (1<<6);
    if(c == 'c')
        k |= (1<<7);
    if(c == 'd')
        k |= (1<<8);
    return k;
}

bool valid(char c, int k){
    if(c == 'A' and !(k & (1<<5)))
        return false;
    if(c == 'B' and !(k & (1<<6)))
        return false;
    if(c == 'C' and !(k & (1<<7)))
        return false;
    if(c == 'D' and !(k & (1<<8)))
        return false;
    return true;
}

bool goal(int k){
    for(int l=0; l<5; ++l){
        if(!(k & (1<<l)))
            return false;
    }
    return true;
}

int32_t main(){
    desync();
    int n, m, ti, tj;
    cin >> n >> m;

    char grid[n][m];
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> grid[i][j];
            if(grid[i][j] == 'T'){
                ti = i;
                tj = j;
            }
        }
    }
    vector<vvi> dp(n, vvi(m, vi(512, LINF)));

    int ans = LINF;

    queue<pair<ii, ii> > q;
    q.emplace(ii(ti, tj), ii(0, 0));

    int di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0};
    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        int i = cur.ff.ff, j = cur.ff.ss, k = cur.ss.ff, d = cur.ss.ss;

        if(d >= dp[i][j][k])
            continue;
        dp[i][j][k] = d;

        if(goal(k))
            ans = min(ans, d);

        for(int l=0; l<4; ++l){
            int li = i+di[l], lj = j+dj[l];
            if(li < 0 or li >= n or lj < 0 or lj >= m)
                continue;

            char c = grid[li][lj];
            if(c == '#')
                continue;

            if(valid(c, k))
                q.emplace(ii(li, lj), ii(activate(c, k), d+1));
        }
    }

    if(ans == LINF)
        cout << "Gamora" << endl;
    else
        cout << ans << endl;
    return 0;
}
