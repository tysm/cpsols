#include <cpplib/stdinc.hpp>

vi ord;
vb vis;
vvi adj;

void dfs(int u){
    vis[u] = true;
    for(int v:adj[u]){
        if(!vis[v])
            dfs(v);
    }
    ord.eb(u);
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        adj = vvi(n);
        vii edges;
        for(int i=0; i<m; ++i){
            int p, a, b;
            cin >> p >> a >> b;
            --a;
            --b;
            if(p == 1)
                adj[a].eb(b);
            edges.eb(a, b);
        }
        ord.clear();
        vis = vb(n);
        for(int i=0; i<n; ++i){
            if(!vis[i])
                dfs(i);
        }
        vi pos(n);
        reverse(all(ord));
        for(int i=0; i<n; ++i)
            pos[ord[i]] = i;
        bool valid = true;
        for(int u=0; u<n; ++u){
            for(int v:adj[u]){
                if(pos[u] > pos[v])
                    valid = false;
            }
        }
        if(valid){
            cout << "YES" << endl;
            for(ii p:edges){
                int a = p.ff, b = p.ss;
                if(pos[a] < pos[b])
                    cout << a+1 << ' ' << b+1 << endl;
                else
                    cout << b+1 << ' ' << a+1 << endl;
            }
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
