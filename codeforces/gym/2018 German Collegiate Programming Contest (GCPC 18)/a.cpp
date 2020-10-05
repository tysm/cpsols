#include <cpplib/stdinc.hpp>
#include <cpplib/graph/lca.hpp>

int n, m;

int conv(int i, int j){
    return m*i + j;
}

int32_t main(){
    desync();
    cin >> n >> m;
    cin.ignore();

    vector<string> grid(n+1);
    for(string &s:grid)
        getline(cin, s);

    vvi adj(n*m);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<2*m+1; j+=2){
            int x = conv(i-1, j/2);

            if(grid[i][j-1] == ' '){
                adj[x].eb(conv(i-1, (j-2)/2));
            }
            if(grid[i][j+1] == ' '){
                adj[x].eb(conv(i-1, (j+2)/2));
            }
            if(grid[i][j] == ' '){
                adj[x].eb(conv(i, j/2));
            }
            if(grid[i-1][j] == ' '){
                adj[x].eb(conv(i-2, j/2));
            }
        }
    }

    LCA lca(adj, 0);

    int q;
    cin >> q;
    q--;

    int i, j;
    cin >> i >> j;

    int cur = conv(i-1, j-1), ans = 0;
    while(q--){
        cin >> i >> j;
        int nxt = conv(i-1, j-1);
        ans += lca.distance(cur, nxt);
        cur = nxt;
    }
    cout << ans << endl;
    return 0;
}
