#include <cpplib/stdinc.hpp>

pair<bool, int> check(vvi &adj, int r){
    vi c(adj.size(), -1);
    queue<int> q;
    c[r] = 0;
    q.push(r);
    int acc = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        acc += c[cur];
        for(int i:adj[cur]){
            if(c[i] == c[cur])
                return {false, -1};
            else if(c[i] == -1){
                c[i] = c[cur]^1;
                q.push(i);
            }
        }
    }
    return {true, acc};
}

int32_t main(){
    desync();
    int n;
    cin >> n;
    vvi adj(n+1);
    for(int i=1; i<n; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    if(n%2){
        cout << 'N' << endl;
        return 0;
    }
    auto ans = check(adj, 1);
    cout << (ans.ff and ans.ss == n/2? 'Y' : 'N') << endl;
    return 0;
}
