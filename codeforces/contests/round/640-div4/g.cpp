#include <cpplib/stdinc.hpp>
#include <cpplib/graph/traversal/depth-first-search.hpp>

void dfs_print(const int u, const vvi &adj, vb &vis){
    vis[u] = true;
    for(int v : adj[u]){
        if(vis[v])
            continue;
        dfs(v, adj, vis);
    }
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    int seq[] = {2, 4, 1, 3};
    while(t--){
        int n;
        cin >> n;

        if(n <= 3){
            cout << -1 << endl;
            continue;
        }

        vi ans;
        for(int i=1; i<=4*(n/4); ++i){
            int v = 4*((i-1)/4) + seq[(i-1)%4];
            ans.pb(v);
        }
        for(int i=4*(n/4)+1; i<=n; ++i)
            ans.pb(i);

        if(n%4 == 2)
            swap(ans[n-2], ans[n-3]);
        else if(n%4 == 3){
            swap(ans[n-3], ans[n-4]);
            swap(ans[n-3], ans[n-2]);
            swap(ans[n-3], ans[n-1]);
        }


        for(int i=0; i<n; ++i){
            if(i)
                cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
