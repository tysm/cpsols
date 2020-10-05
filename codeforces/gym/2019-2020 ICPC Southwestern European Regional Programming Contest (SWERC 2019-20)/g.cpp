#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int s, l, n;
    cin >> s >> l >> n;

    vector<string> arr(s);
    for(string &x:arr)
        cin >> x;
    sort(all(arr));

    map<string, int> sidx;
    for(int i=0; i<s; ++i)
        sidx[arr[i]] = i;

    vvb adj(s, vb(s));
    for(int i=0; i<l; ++i){
        string a, b;
        cin >> a >> b;
        int ai = sidx[a], bi = sidx[b];
        adj[ai][bi] = adj[bi][ai] = true;
    }

    vi seq(n);
    for(int &i:seq){
        string x;
        cin >> x;
        i = sidx[x];
    }

    vi vis(n), cur(s);
    vector<string> ans;
    for(int k=0; k<n; ++k){
        for(int i=0; i<s; ++i){
            int &c = cur[i];
            while(c < n and (vis[c] or adj[i][seq[c]]))
                c++;
        }
        for(int i=0; i<s; ++i){
            int c = cur[i];
            if(c >= n)
                continue;
            if(seq[c] != i)
                continue;
            ans.eb(arr[i]);
            vis[c] = true;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
