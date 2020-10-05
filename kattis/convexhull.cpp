#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/geo/cvhull.hpp>

int32_t main(){
    desync();
    int n;
    while(cin >> n, n){
        set<point<int> > pts;
        for(int i=0; i<n; ++i){
            point<int> p;
            cin >> p.x >> p.y;
            pts.ep(p);
        }
        auto ans = get<0>(convex_hull(vector<point<int> >(all(pts))));
        cout << ans.size() << endl;
        for(auto &i:ans)
            cout << i.x << ' ' << i.y << endl;
    }
    return 0;
}
