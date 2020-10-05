#include <cpplib/stdinc.hpp>
#include <cpplib/graph/shortest-path/floyd-warshall.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1672
    desync();
    int n, m, q, max_dis = INF*INF;
    cin >> n >> m >> q;
    vvi dis(n+1, vi(n+1, max_dis));
    for(int i=0; i<=n; ++i)
        dis[i][i] = 0;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = dis[b][a] = min(c, dis[b][a]);
    }
    dis = floyd(dis, max_dis);
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << (dis[a][b] == max_dis? -1 : dis[a][b]) << endl;
    }
    return 0;
}
