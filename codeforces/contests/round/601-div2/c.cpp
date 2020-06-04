#include <cpplib/stdinc.hpp>

void dfs(vvi &adj, vvi &arr, vi &cnt, int u, int p = -1){
    for(int i:arr[u]){
        if(cnt[i]){
            cnt[i]--;
            if(!cnt[i])
                cout << i << ' ';
        }
    }
    for(int v:adj[u]){
        if(v == p)
            continue;
        dfs(adj, arr, cnt, v, u);
    }
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi cnt(n+1);
    vvi arr(n-2), adj(n-2);
    map<ii, int> link;
    for(int i=0; i<n-2; ++i){
        vi &v = arr[i];

        int a, b, c;
        cin >> a >> b >> c;
        cnt[a]++;
        cnt[b]++;
        cnt[c]++;

        v = {a, b, c};
        for(int j=0; j<2; ++j){
            for(int k=j+1; k<3; ++k){
                if(k == j)
                    continue;
                ii aux = {v[j], v[k]};
                if(link.count(aux)){
                    adj[i].pb(link[aux]);
                    adj[link[aux]].pb(i);
                }
                else{
                    link[aux] = i;
                    link[{v[k], v[j]}] = i;
                }
            }
        }
    }
    for(vi &v:arr)
        sort(v.begin(), v.end(), [&cnt](int i, int j){ return cnt[i] > cnt[j]; });
    for(int i=0; i<n-2; ++i){
        int a = arr[i][0], b = arr[i][1], c = arr[i][2];
        if(cnt[a] == 1 or cnt[b] == 1 or cnt[c] == 1){
            dfs(adj, arr, cnt, i);
            cout << endl;
            break;
        }
    }
    return 0;
}
