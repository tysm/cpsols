#include <cpplib/stdinc.hpp>
#include <cpplib/graph/traversal/breadth-first-search.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1667/
    desync();
    int n, m;
    cin >> n >> m;
    vvi adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    auto res = bfs(1, adj);
    if(res.ss[n] == -1)
        cout << "IMPOSSIBLE" << endl;
    else{
        vi ans;
        int p = n;
        while(p != -1){
            ans.pb(p);
            p = res.ss[p];
        }
        cout << ans.size() << endl;
        for(int i=ans.size()-1; i>=0; --i){
            if(i != ans.size()-1)
                cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
