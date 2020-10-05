#include <cpplib/stdinc.hpp>
#include <cpplib/graph/2-sat.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vi r(n);
    for(int &i:r)
        cin >> i;

    vvi swi(n);
    for(int i=0; i<m; ++i){
        int x;
        cin >> x;
        for(int j=0; j<x; ++j){
            int d;
            cin >> d;
            swi[d-1].eb(i);
        }
    }

    vii props;
    for(int i=0; i<n; ++i){
        if(r[i]){ // -(p^q).
            props.eb(2*swi[i][0], 2*swi[i][1]+1);
            props.eb(2*swi[i][0]+1, 2*swi[i][1]);
        }
        else{ // (p^q).
            props.eb(2*swi[i][0], 2*swi[i][1]);
            props.eb(2*swi[i][0]+1, 2*swi[i][1]+1);
        }
    }

    cout << (check(m, props)? "YES" : "NO") << endl;
    return 0;
}
