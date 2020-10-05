#include <cpplib/stdinc.hpp>
#include <cpplib/graph/scc.hpp>
#include <cpplib/graph/2-sat.hpp>

void dfs(vvi &adj, vb &vis, int u){
    vis[u] = true;
    for(int v:adj[u]){
        if(vis[v])
            continue;
        dfs(adj, vis, v);
    }
}

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vii disj;
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        u = 2*(abs(u)-1) + (u < 0);
        v = 2*(abs(v)-1) + (v < 0);
        disj.eb(u, v);
    }

    int ans = 3;
    auto dag = graph(n, disj);
    vvi idag(dag.size());
    for(int i=0; i<dag.size(); ++i){
        for(int j:dag[i])
            idag[j].eb(i);
    }
    for(int i=0; i<n; ++i){
        vb fi(2*n), fi1(2*n), ri(2*n), ri1(2*n);
        dfs(dag, fi, 2*i);
        dfs(dag, fi1, 2*i+1);
        dfs(idag, ri, 2*i);
        dfs(idag, ri1, 2*i+1);

        if(fi[2*i+1] and fi1[2*i]){
            ans = 0;
            break;
        }

        bool neg = false, pos = false;
        for(int j=0; j<2*n; ++j){
            if(j%2 and fi[j] and fi1[j])
                neg = true;
            if(j%2 == 0 and ri[j] and ri1[j])
                pos = true;
        }
        if(neg and pos)
            ans = min(ans, (int)1);
        bool negi = false, negi1 = false, posi = false, posi1 = false;
        for(int j=0; j<2*n; ++j){
            if(j%2){
                if(fi[j])
                    negi = true;
                if(fi1[j])
                    negi1 = true;
            }
            else{
                if(ri[j])
                    posi = true;
                if(ri1[j])
                    posi1 = true;
            }
        }
        if(negi and negi1 and posi and posi1)
            ans = min(ans, (int)2);
    }
    cout << (ans == 3? -1 : ans) << endl;
    return 0;
}
