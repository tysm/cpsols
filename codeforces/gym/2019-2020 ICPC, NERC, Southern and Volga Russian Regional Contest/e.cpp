#include <cpplib/stdinc.hpp>

tuple<int, int> dist(string &a, string &b){
    int m = a.size(), k1 = 0, k2 = 0;
    for(int i=0, j=m-1; i<m; ++i, j--){
        k1 += (a[i] == b[i]);
        k2 += (a[i] == b[j]);
    }
    return make_tuple(k1, k2);
}

void dfs(vvii &adj, vi &color, vi &cnt, vi &cur, bool &valid, int u){
    cur.eb(u);
    cnt[color[u]]++;
    for(ii i:adj[u]){
        int v = i.ff, w = i.ss;
        if(color[v] == -1){
            color[v] = color[u];
            if(!w)
                color[v] ^= 1;
            dfs(adj, color, cnt, cur, valid, v);
        }
        else{
            if(!w and color[v] == color[u])
                valid = false;
            if(w and color[v] != color[u])
                valid = false;
        }
    }
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> arr(n);
        for(string &s:arr)
            cin >> s;
        bool valid = true;
        vvii adj(n);
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int k1, k2;
                tie(k1, k2) = dist(arr[i], arr[j]);
                if(k1 >= k and k2 >= k)
                    continue;
                else if(k1 >= k){
                    adj[i].eb(j, 1);
                    adj[j].eb(i, 1);
                }
                else if(k2 >= k){
                    adj[i].eb(j, 0);
                    adj[j].eb(i, 0);
                }
                else
                    valid = false;
            }
        }
        vi color(n, -1), ans;
        for(int i=0; i<n; ++i){
            if(color[i] != -1)
                continue;
            color[i] = 0;
            vi cnt(2), cur;
            dfs(adj, color, cnt, cur, valid, i);
            int minc = (cnt[0] < cnt[1]? 0 : 1);
            for(int j:cur){
                if(color[j] != minc)
                    continue;
                ans.eb(j+1);
            }
        }
        if(!valid){
            cout << -1 << endl;
            continue;
        }
        cout << ans.size() << endl << ans << endl;
    }
    return 0;
}
