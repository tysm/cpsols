#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1668
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
    vi color(n+1);
    bool possible = true;
    for(int i=1; i<=n and possible; ++i){
        if(color[i])
            continue;
        color[i] = 1;

        queue<int> q; q.push(i);
        while(!q.empty()){
            int u = q.front(); q.pop();

            for(int v:adj[u]){
                if(!color[v]){
                    color[v] = color[u]%2 + 1;
                    q.push(v);
                }
                else if(color[v] != color[u]%2 + 1){
                    possible = false;
                    break;
                }
            }
            if(!possible)
                break;
        }
    }
    if(!possible)
        cout << "IMPOSSIBLE" << endl;
    else{
        for(int i=1; i<=n; ++i){
            if(i != 1)
                cout << ' ';
            cout << color[i];
        }
        cout << endl;
    }
    return 0;
}
