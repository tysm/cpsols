#include <cpplib/stdinc.hpp>
#include <cpplib/adt/heap.hpp>

int32_t main(){
    ifstream cin("balls.in");
    desync();
    int t;
    cin >> t;
    while(t--){
        int r, c;
        cin >> r >> c;

        vi balls(c);
        for(int &i:balls)
            cin >> i;

        vector<string> grid(r);
        for(string &s:grid)
            cin >> s;

        vii scr;
        for(int i=0; i<c; ++i){
            int x;
            cin >> x;
            scr.eb(x, i);
        }
        sort(rall(scr));

        int ans = 0;
        vvb vis(r, vb(c));
        for(int k=0; k<c; ++k){
            int x = scr[k].ff, j = scr[k].ss;
            queue<ii> q;
            if(!vis[r-1][j]){
                vis[r-1][j] = true;
                q.emplace(r-1, j);
            }
            if(j-1 >= 0 and !vis[r-1][j-1] and grid[r-1][j-1] != '.'){
                vis[r-1][j-1] = true;
                q.emplace(r-1, j-1);
            }
            if(j+1 < c and !vis[r-1][j+1] and grid[r-1][j+1] != '.'){
                vis[r-1][j+1] = true;
                q.emplace(r-1, j+1);
            }
            while(!q.empty()){
                int i = q.front().ff, j = q.front().ss;
                q.pop();
                if(!i){
                    ans += x*balls[j];
                    continue;
                }
                if(!vis[i-1][j]){
                    vis[i-1][j] = true;
                    q.emplace(i-1, j);
                }
                if(j-1 >= 0 and !vis[i-1][j-1] and grid[i-1][j-1] != '.'){
                    vis[i-1][j-1] = true;
                    q.emplace(i-1, j-1);
                }
                if(j+1 < c and !vis[i-1][j+1] and grid[i-1][j+1] != '.'){
                    vis[i-1][j+1] = true;
                    q.emplace(i-1, j+1);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
