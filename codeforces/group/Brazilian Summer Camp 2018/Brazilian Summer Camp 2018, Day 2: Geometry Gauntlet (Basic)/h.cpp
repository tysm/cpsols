#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/adt/polygon.hpp>

int32_t main(){
    desync();
    int n, m, k;
    cin >> n >> m >> k;

    vector<point<int> > pts(n);
    for(auto &p:pts)
        cin >> p.x >> p.y;
    polygon<int> pl(pts);

    while(m--){
        point<int> pt;
        cin >> pt.x >> pt.y;
        k -= count(pl, pt);
    }
    cout << (k <= 0? "YES" : "NO") << endl;
    return 0;
}
