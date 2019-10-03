#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

using ii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vii = vector<ii>;

#define ff first
#define ss second
#define pb push_back

#define EPS 1e-9
#define INF (int32_t(1e9)+1)
#define MAX (int32_t(1e6)+1)
#define M (int32_t(1e9)+7)

#define endl "\n"
#define debug(x) (cerr << #x << " = " << (x) << endl)
#define desync() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

int n, m;
char grid[50][50];
int dp[50][50];

/**
 * Depth First Search.
 *
 * Performs a Depth First Search in a
 * graph given its vertex adjacencies.
 *
 * Time Complexity: O(n + m).
 * Where n is the size of the graph and m is the quantity of edges.
 */
int dfs(int ui, int uj){
    if(dp[ui][uj])
        return dp[ui][uj];

    int di[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dj[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    int ans = 0;
    for(int k=0; k<8; ++k){
        int i = ui+di[k];
        int j = uj+dj[k];
        if(i<0 or j<0 or i>=n or j>=m)
            continue;
        if((int)grid[i][j] - (int)grid[ui][uj] != 1)
            continue;
        ans = max(ans, dfs(i, j));
    }
    return dp[ui][uj] = ans + 1;
}

int32_t main(){
    desync();
    int c = 0;
    while(cin >> n >> m, n+m){
        vii sv;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin >> grid[i][j];
                if(grid[i][j] == 'A')
                    sv.pb({i, j});
            }
        }
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(ii p : sv)
            ans = max(ans, dfs(p.ff, p.ss));
        cout << "Case " << ++c << ": " << ans << endl;
    }
    return 0;
}
