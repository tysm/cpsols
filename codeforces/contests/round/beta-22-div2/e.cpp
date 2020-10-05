#include <cpplib/stdinc.hpp>
#include <cpplib/graph/scc.hpp>

int dfs(vvi &dag, vb &vis, int u){
    vis[u] = true;
    if(dag[u].empty())
        return u;
    for(int v:dag[u]){
        if(vis[v])
            continue;
        int res = dfs(dag, vis, v);
        if(res != -1)
            return res;
    }
    return -1;
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    vvi adj(n);
    for(vi &v:adj){
        int x;
        cin >> x;
        v.eb(x-1);
    }

    auto [dag, repr] = scc(adj);
    int k = dag.size();
    if(k == 1){
        cout << 0 << endl;
        return 0;
    }

    vi irepr(k); // node to represent a condensed node.
    for(int i=0; i<n; ++i)
        irepr[repr[i]] = i+1;

    vi in(k), out(in); // indegree outdegree.
    for(int i=0; i<k; ++i){
        for(int j:dag[i]){
            in[j]++;
            out[i]++;
        }
    }

    vi src, sink;
    vb vis(k), used(k);
    for(int i=0; i<k; ++i){
        if(in[i] != 0)
            continue;
        int res = dfs(dag, vis, i);
        if(res != -1){
            used[i] = true;
            used[res] = true;
            src.eb(irepr[i]);
            sink.eb(irepr[res]);
        }
    }

    vii ans; // ans.size is going to be max(in[i] == 0, out[j] == 0)
    int w = src.size();
    for(int i=0; i<w; ++i)
        ans.eb(sink[i], src[(i+1)%w]);

    vi src1, sink1;
    for(int i=0; i<k; ++i){
        if(in[i] == 0 and !used[i])
            src1.eb(irepr[i]);
        if(out[i] == 0 and !used[i])
            sink1.eb(irepr[i]);
        used[i] = true;
    }

    int z = min(src1.size(), sink1.size());
    for(int i=0; i<z; ++i){
        ans.eb(sink1.back(), src1.back());
        sink1.pop_back();
        src1.pop_back();
    }

    while(!sink1.empty()){
        ans.eb(sink1.back(), src[0]);
        sink1.pop_back();
    }
    while(!src1.empty()){
        ans.eb(sink[0], src1.back());
        src1.pop_back();
    }

    cout << ans.size() << endl;
    for(auto p:ans)
        cout << p << endl;
    return 0;
}
