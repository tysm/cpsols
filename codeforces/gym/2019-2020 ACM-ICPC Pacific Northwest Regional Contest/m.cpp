#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define ii pair<int, int>
#define OK (cerr << "OK" << endl)
#define debug(x) cerr << #x " = " << (x) << endl
#define ff first
#define ss second
#define int long long
#define tt tuple<int, int, int>
#define all(x) x.begin(), x.end()
#define Matrix vector<vector<int>>
#define Mat(n, m, v) vector<vector<int>>(n, vector<int>(m, v))
#define endl '\n'

constexpr int INF = 2e18;
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e3 + 3;

char lo[2][2] = {{'/', '\\'}, {'\\', '/'}};
int vis[MAXN][MAXN];
char mat[MAXN][MAXN];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n;
int m;
void dfs(int x, int y) {
  vis[x][y] = true;
  for (int k = 0; k < 4; ++k) {
    int nx = dx[k] + x, ny = dy[k] + y;
    if (0 <= nx && nx < n && 0 <= ny && ny < m && mat[nx][ny] == '.' &&
        !vis[nx][ny]) {
      dfs(nx, ny);
    }
  }

  if(x+1 < n and y+1 < m and mat[x+1][y+1] == '.' and !vis[x+1][y+1]){
      if(!(mat[x+1][y] == '/' and mat[x][y+1] == '/'))
          dfs(x+1, y+1);
  }
  if(x+1 < n and y-1 >= 0 and mat[x+1][y-1] == '.' and !vis[x+1][y-1]){
      if(!(mat[x+1][y] == '\\' and mat[x][y-1] == '\\'))
          dfs(x+1, y-1);
  }
  if(x-1 >= 0 and y-1 >= 0 and mat[x-1][y-1] == '.' and !vis[x-1][y-1]){
      if(!(mat[x-1][y] == '/' and mat[x][y-1] == '/'))
          dfs(x-1, y-1);
  }
  if(x-1 >= 0 and y+1 < m and mat[x-1][y+1] == '.' and !vis[x-1][y+1]){
      if(!(mat[x-1][y] == '\\' and mat[x][y+1] == '\\'))
          dfs(x-1, y+1);
  }
}

void solve() {
  cin >> n;

  cin >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  for(int i=0; i<n; ++i){
      if(mat[i][0] == '.' and !vis[i][0])
          dfs(i, 0);
      if(mat[i][m-1] == '.' and !vis[i][m-1])
          dfs(i, m-1);
  }
  for(int j=0; j<m; ++j){
      if(mat[0][j] == '.' and !vis[0][j])
          dfs(0, j);
      if(mat[n-1][j] == '.' and !vis[n-1][j])
          dfs(n-1, j);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '.' && !vis[i][j]) {
        dfs(i, j);
        ++ans;
      } else if (i + 1 < n && j + 1 < m) {
        bool ok = true;
        for (int k = 0; k < 2; ++k)
          for (int l = 0; l < 2; ++l)
            if (mat[i + k][j + l] != lo[k][l])
              ok = false;
        ans += ok;
      }
    }
  }
  cout << ans << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
#ifdef MULTIPLE_TEST_CASES
  cin >> t;
#endif
  while (t--)
    solve();
}
