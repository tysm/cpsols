#include <cpplib/stdinc.hpp>
#include <cpplib/graph/shortest-path/bellman-ford.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1673
    desync();
    int n, m;
    cin >> n >> m;
    vvii adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, -c});
    }
    int inf = INF*INF;
    pair<vi, vi> ans = bellman(1, adj, inf);
    cout << (abs(ans.ss[n]) == inf? -1 : -ans.ss[n]) << endl;
    return 0;
}
