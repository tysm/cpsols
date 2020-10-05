#include <cpplib/stdinc.hpp>

int n;
vii arr;
vb vis(1<<20);
vvii adj(1<<20);

void dfs(int u){
    vis[u] = true;
    for(auto [v, idx] : adj[u]){
        if(vis[v])
            continue;
        dfs(v);
    }
}

bool check(int b){
    for(int i=0; i<=b; ++i){
        adj[i].clear();
        vis[i] = false;
    }

    for(int i=0; i<n; ++i){
        auto [u, v] = arr[i];
        u &= b;
        v &= b;

        adj[u].eb(v, 2*i+1);
        adj[v].eb(u, 2*i);
    }

    int res = 0;
    for(int i=0; i<=b; ++i){
        if(adj[i].size()%2)
            return false;

        if(!vis[i] and !adj[i].empty()){
            res++;
            dfs(i);
        }
    }
    return res == 1;
}

void euler(int u, vi &ans, int p = -1){
    while(!adj[u].empty()){
        auto [v, idx] = adj[u].back();
        adj[u].pop_back();

        if(vis[idx/2])
            continue;

        vis[idx/2] = true;
        euler(v, ans, idx);
    }

    if(p != -1){
        ans.eb(p+1);
        ans.eb((p^1)+1);
    }
}

void solve(int b){
    vis.assign(n, false);

    for(int i=0; i<=b; ++i){
        if(adj[i].empty())
            continue;
        vi ans;
        euler(i, ans);
        cout << ans << endl;
        break;
    }

}

int32_t main(){
    cin >> n;

    arr.resize(n);
    for(ii &i:arr)
        cin >> i.ff >> i.ss;

    for(int b=20; b>=0; --b){
        if(check((1<<b)-1)){
            cout << b << endl;
            solve((1<<b)-1);
            break;
        }
    }
    return 0;
}
