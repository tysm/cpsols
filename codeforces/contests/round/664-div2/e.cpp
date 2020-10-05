#include <cpplib/stdinc.hpp>
#include <cpplib/adt/hashint.hpp>

int k;
hint uni;
vector<vector<hint> > tup(10);

int solve(int i, hint cur){
    if(i > k)
        return cur == uni;

    int res = 0;
    for(int ci=1; ci<=i; ++ci)
        res += solve(i+1, cur+tup[i][ci]);
    return res;
}

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m >> k;

    vvii adj(n+1);
    for(int i=0; i<m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].eb(w, v);
    }

    for(int u=1; u<=n; ++u)
        uni += u;
    for(int i=1; i<=k; ++i)
        tup[i].resize(i+1);

    for(int u=1; u<=n; ++u){
        sort(all(adj[u]));

        int dot = adj[u].size();
        for(int ci=1; ci<=dot; ++ci){
            int v = adj[u][ci-1].ss;
            tup[dot][ci] += v;
        }
    }

    cout << solve(1, hint()) << endl;
    return 0;
}
