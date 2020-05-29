#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m, t;
    cin >> n >> m >> t;
    int cx = 0, cy = 0, li = 0, ri = 0, lc = 0, rc = 0;
    for(int i=0; i<t; ++i){
        char op;
        cin >> op;
        if(op == 'C')
            cx++;
        else if(op == 'D')
            cy++;
        else if(op == 'B')
            cx--;
        else
            cy--;
        li = min(li, cx);
        ri = max(ri, cx);
        lc = min(lc, cy);
        rc = max(rc, cy);
    }
    vii ans;
    for(int i=0; i<n; ++i){
        if(i+li < 0)
            continue;
        if(i+ri >= n)
            continue;
        for(int j=0; j<m; ++j){
            if(j+lc < 0)
                continue;
            if(j+rc >= m)
                continue;
            ans.pb({i+cx, j+cy});
        }
    }
    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); ++i)
        cout << ans[i].ff+1 << ' ' << ans[i].ss+1 << endl;
    return 0;
}
