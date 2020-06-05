#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define MAX (int32_t(1e6)+1)
#define INF (int32_t(1e9)+1)
using namespace std;

vi adj[MAX];
vii leafs;

void dfs(int s, int nvl){
    if(adj[s].empty())
        leafs.pb({nvl, s});
    for(auto i:adj[s])
        dfs(i, nvl+1);
}

int32_t main(){
    int n, k;
    cin >> n >> k;
    int p[MAX] = {};
    for(int i=2; i<=n; ++i){
        cin >> p[i];
        adj[p[i]].pb(i);
    }
    dfs(1, 0);
    sort(leafs.rbegin(), leafs.rend());
    vi outs, vis(MAX, 0);
    for(auto l:leafs){
        int i = l.ss, res = 1;
        vis[i] = true;
        while(p[i] and !vis[p[i]]){
            i = p[i];
            vis[i] = true;
            res++;
        }
        outs.pb(res);
    }
    sort(outs.rbegin(), outs.rend());
    int ans = 0;
    for(int i=0; i<min(k, (int)outs.size()); ++i)
        ans += outs[i];
    cout << ans << endl;
    return 0;
}
