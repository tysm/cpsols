#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m, q;
    cin >> n >> m >> q;

    set<ii> vis;
    for(int i=0; i<q; ++i){
        int a, b;
        cin >> a >> b;
        vis.emplace(a-1, b-1);
    }

    int ans = LINF;

    int c1 = 0, c2 = 0;
    for(int i=0; i<m; ++i){
        if(!vis
    }
    return 0;
}
