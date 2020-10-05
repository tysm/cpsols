#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/adt/polygon.hpp>
#include <cpplib/geo/cvhull.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vector<point<int> > ntz(n);
    for(auto &i:ntz)
        cin >> i.x >> i.y;
    polygon<int> pl(get<0>(convex_hull(ntz)));
    int s;
    cin >> s;
    int ans = 0;
    for(int i=0; i<s; ++i){
        point<int> pt;
        cin >> pt.x >> pt.y;
        ans += count(pl, pt);
    }
    cout << ans << endl;
    return 0;
}
