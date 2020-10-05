#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<ii, int> vis;

    int x = 0, y = 0;
    vis[ii(x, y)] = 0;

    bool colid = false;
    int acc = 0, ans = 0;
    for(int i=1; i<=n; ++i){
        char c = s[i-1];
        if(c == 'R')
            x++;
        else if(c == 'L')
            x--;
        else if(c == 'U')
            y++;
        else
            y--;
        if(vis.count(ii(x, y)))
            colid = true;
        if(vis[ii(x, y)] > acc)
            acc = vis[ii(x, y)];
        ans = max(ans, i-acc-colid);
        vis[ii(x, y)] = i;
    }
    cout << ans << endl;
    return 0;
}
