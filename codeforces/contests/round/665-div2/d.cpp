#include <cpplib/stdinc.hpp>
#include <cpplib/adt/heap.hpp>
#include <cpplib/adt/modular.hpp>

int n;
vector<int> coef;

int dfs(vvi &adj, int u, int p=-1){
    int res = 1;
    for(int v:adj[u]){
        if(v == p)
            continue;

        int aux = dfs(adj, v, u);
        res += aux;

        coef.eb(aux*(n-aux));
    }
    return res;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        coef.clear();

        cin >> n;

        vvi adj(n);
        for(int i=1; i<n; ++i){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].eb(v);
            adj[v].eb(u);
        }
        dfs(adj, 0);
        sort(rall(coef));

        int m;
        cin >> m;

        max_heap<int> pq;
        for(int i=0; i<m; ++i){
            int x;
            cin >> x;
            pq.ep(x);
        }
        while(pq.size() < n-1)
            pq.ep(1);

        vector<mint> prim;
        while(!pq.empty()){
            if(prim.empty())
                prim.eb(pq.top());
            else if(pq.size() + prim.size() > n-1)
                prim.back()*=pq.top();
            else
                prim.eb(pq.top());
            pq.pop();
        }

        mint ans = 0;
        for(int i=0; i<n-1; ++i)
            ans += ((mint)prim[i])*coef[i];
        cout << ans << endl;
    }
    return 0;
}
