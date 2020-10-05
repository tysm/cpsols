#include <cpplib/stdinc.hpp>
#include <cpplib/graph/2-sat.hpp>

int32_t main(){
    desync();
    int n, p, M, m;
    cin >> n >> p >> M >> m;

    vii props;
    for(int i=0; i<n; ++i){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        props.eb(2*u, 2*v); // city must establish with (u or v).
    }

    for(int i=0; i<p; ++i){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if(l != 0)
            props.eb((l-1 + p)*2, 2*i + 1);
        if(r != M-1)
            props.eb((r + p)*2 + 1, 2*i + 1);
    }

    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        props.eb(2*u+1, 2*v+1); // city must not establish with (u and v) -> (!u or !v).
    }

    for(int u = 0; u<=M-3; ++u){
        int v = u+1;
        props.eb(2*(u+p), 2*(v+p)+1);
    }

    vb res = solve(graph(p+M-1, props));
    if(res.empty())
        cout << -1 << endl;
    else{
        int ans = 0, f = 1;
        vi stations;
        for(int i=0; i<res.size(); ++i){
            if(res[i]){
                if(i < p)
                    stations.eb(i+1);
                else
                    f = max(f, i+2-p);
            }
        }
        cout << stations.size() << ' ' << f << endl;
        cout << stations << endl;
    }
    return 0;
}
