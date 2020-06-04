#include <cpplib/stdinc.hpp>

int32_t main(){
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
    vii ass;
    for(int i=1; i<=n; ++i){
        int c;
        cin >> c;
        ass.pb({c, i});
    }
    sort(all(ass));

    bool valid = true;
    vi ans, clr(n+1);
    for(ii &i:ass){
        int c = i.ff, u = i.ss;

        vi adjc;
        for(int v:adj[u]){
            if(clr[v])
                adjc.pb(clr[v]);
        }
        sort(all(adjc));

        int mex = 1;
        for(int j:adjc){
            if(mex == j)
                mex++;
        }

        if(mex != c){
            valid = false;
            break;
        }

        clr[u] = c;
        ans.pb(u);
    }
    if(valid){
        for(int i=0; i<ans.size(); ++i){
            if(i)
                cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}
