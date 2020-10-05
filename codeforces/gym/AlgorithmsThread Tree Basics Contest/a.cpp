#include <cpplib/stdinc.hpp>
#include <cpplib/graph/treedmtr.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vvi adj(n);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].eb(b);
        adj[b].eb(a);
    }
    int d = get<2>(tree_diameter(adj));
    cout << 3*d << endl;
    return 0;
}
