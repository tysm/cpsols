#include <cpplib/stdinc.hpp>

bool dfs(map<char, set<char> > &adj, map<char, int> &vis, char u, char p = 'A'){
    vis[u] = 1;
    for(char v:adj[u]){
        if(v == p or vis[v] == 2)
            continue;
        else if(vis[v] == 1 or dfs(adj, vis, v, u))
            return true;
    }
    vis[u] = 2;
    return false;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        map<char, set<char> > adj;
        bool ok = true;
        for(int i=1; i<s.size(); ++i){
            char a = s[i-1], b = s[i];
            adj[a].insert(b);
            adj[b].insert(a);
            if(adj[a].size() > 2 or adj[b].size() > 2)
                ok = false;
        }
        map<char, int> mvis;
        if(!ok or dfs(adj, mvis, s[0]))
            cout << "NO" << endl;
        else{
            string ans;
            set<char> vis;
            for(char c:s){
                if(vis.count(c) or adj[c].size() != 1)
                    continue;
                ans += c;
                vis.insert(c);
                c = *adj[c].begin();
                while(!vis.count(c)){
                    ans += c;
                    vis.insert(c);
                    for(char b:adj[c]){
                        if(!vis.count(b)){
                            c = b;
                            break;
                        }
                    }
                }
            }
            for(char c='a'; c<='z'; ++c){
                if(!vis.count(c))
                    ans += c;
            }
            cout << "YES" << endl;
            cout << ans << endl;
        }
    }
    return 0;
}
