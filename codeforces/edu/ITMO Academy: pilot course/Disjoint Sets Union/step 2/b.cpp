#include <cpplib/stdinc.hpp>
#include <cpplib/adt/dsu.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi ans(n);
    iota(all(ans), 0);

    DSU dsu(n+1);
    vi out;
    for(int i=0; i<n; ++i){
        int pos;
        cin >> pos;
        pos--;

        int res = ans[dsu.find(pos)];
        out.eb(res+1);

        int res_r = ans[dsu.find((res+1)%n)];
        dsu.merge(res, (res+1)%n);
        ans[dsu.find(res)] = res_r;
    }
    cout << out << endl;
    return 0;
}
