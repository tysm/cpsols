#include <cpplib/stdinc.hpp>

short n;
vector<short> vis(1<<12);
vector<vector<short> > adj(1<<12);

bool ok(short s, short t){
    short cnt = 0;
    for(short i=0; i<n; ++i){
        if((s&1)^(t&1))
            cnt++;
        s >>= 1;
        t >>= 1;
    }
    return cnt >= n/2;
}

void print(short s){
    for(short i=0; i<n; ++i, s>>=1)
        cout << (s&1);
    cout << endl;
}

vector<short> ans;
void dfs(short u){
    vis[u] = true;
    for(short v:adj[u]){
        if(vis[v])
            continue;
        if(!ans.empty() and !ok(v, ans.back()))
            continue;
        dfs(v);
    }
    ans.eb(u);
}

int32_t main(){
    desync();
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);

    cin >> n;

    for(short i=0; i<(1<<n); ++i){
        for(short j=i+1; j<(1<<n); ++j){
            if(ok(i, j)){
                adj[i].eb(j);
                adj[j].eb(i);
            }
        }
    }

    dfs(0);
    for(short &i:ans)
        print(i);
    return 0;
}
