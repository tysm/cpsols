#include <cpplib/stdinc.hpp>

int t;
vi par, dis, tin, tout;
vvi adj;

void dfs(int u, int p = -1){
    if(p >= 0){
        par[u] = p;
        dis[u] = dis[p]+1;
    }
    tin[u] = t++;
    for(int v:adj[u]){
        if(v == p)
            continue;
        dfs(v, u);
    }
    tout[u] = t++;
}

bool isAnc(int v, int u){
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int32_t main(){
    int n, m;
    scanf("%lld %lld", &n, &m);
    t = 0;
    par.resize(n);
    dis.resize(n);
    tin.resize(n);
    tout.resize(n);
    adj.resize(n);
    for(int i=1; i<n; ++i){
        int a, b;
        scanf("%lld %lld", &a, &b);
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    dfs(0);
    while(m--){
        int k;
        scanf("%lld", &k);

        vi arr(k);
        for(int &i:arr){
            scanf("%lld", &i);
            i--;
        }

        int u = arr[0];
        for(int v:arr){
            if(dis[v] > dis[u])
                u = v;
        }
        bool valid = true;
        for(int v:arr)
            valid &= isAnc(par[v], u);
        printf(valid? "YES\n" : "NO\n");
    }
    return 0;
}
