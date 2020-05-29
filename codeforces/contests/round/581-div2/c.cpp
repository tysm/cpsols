#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int adj[101][101] = {};
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i){
        string s;
        cin >> s;
        for(int j=0; j<s.size(); ++j){
            if(s[j] == '1')
                adj[i][j+1] = true;
            else
                adj[i][j+1] = INF;
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            for(int k=1; k<=n; ++k)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        }
    }
    int m;
    cin >> m;
    vi grf(m);
    for(int i=0; i<m; ++i)
        cin >> grf[i];

    vi ans;
    for(int i=0; i<m; ++i){
        int x = grf[i];
        ans.pb(x);
        int aux = i;
        for(int j=i+1; j<m-1; ++j){
            int y = grf[j], z = grf[j+1];
            int xz = j+1 - i;
            if(adj[x][z] < xz or (x == z and adj[x][z] != INF)){
                break;
            }
            aux = j;
        }
        i = aux;
    }

    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); ++i){
        if(i)
            cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
