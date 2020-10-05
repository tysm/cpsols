#include <cpplib/stdinc.hpp>
#include <cpplib/adt/dsu.hpp>

int32_t main(){
    desync();
    int n, m, q;
    cin >> n >> m >> q;

    DSU dsu(n);
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
    }

    vector<tuple<string, int, int> > qr;
    for(int i=0; i<q; ++i){
        string s;
        int u, v;
        cin >> s >> u >> v;
        u--;
        v--;
        qr.eb(s, u, v);
    }
    reverse(all(qr));

    vector<string> ans;
    for(int i=0; i<q; ++i){
        auto [s, u, v] = qr[i];
        if(s == "ask")
            ans.eb(dsu.same(u, v)? "YES" : "NO");
        else
            dsu.merge(u, v);
    }
    reverse(all(ans));
    for(string &s:ans)
        cout << s << endl;
    return 0;
}
