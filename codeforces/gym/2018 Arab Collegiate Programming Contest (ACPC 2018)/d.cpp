#include <cpplib/stdinc.hpp>

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    set<int> xvals, yvals;
    xvals.ep(0);
    yvals.ep(0);
    xvals.ep(n+1);
    yvals.ep(m+1);

    vii pts(k);
    for(auto &[x, y]:pts){
        cin >> x >> y;
        xvals.ep(x);
        yvals.ep(y);
    }

    int nx = 0, ny = 0;
    map<int, int> compx, compy;
    vi dcompx, dcompy;
    for(int x:xvals){
        compx[x] = nx++;
        dcompx.eb(x);
    }
    for(int y:yvals){
        compy[y] = ny++;
        dcompy.eb(y);
    }

    vvi grid(nx, vi(ny));
    for(auto [x, y] : pts)
        grid[compx[x]][compy[y]]++;

    int ans = 0;
    for(int i=1; i<nx-1; ++i){
        for(int j=1; j<ny-1; ++j){
            grid[i][j] += grid[i-1][j];
            grid[i][j] += grid[i][j-1];
            grid[i][j] -= grid[i-1][j-1];

            int dx = dcompx[i+1] - dcompx[i], dy = dcompy[j+1] - dcompy[j];
            if(grid[i][j] & 1)
                ans += dx*dy;
        }
    }
    cout << ans << ' ' << n*m-ans << endl;
}

int32_t main(){
    desync();
    freopen("dull.in", "r", stdin);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
