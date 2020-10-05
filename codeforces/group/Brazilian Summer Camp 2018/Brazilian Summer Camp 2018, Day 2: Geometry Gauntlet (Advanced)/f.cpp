#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/geo/clstpair.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vector<point<int> > arr(n);
    for(auto &p:arr)
        cin >> p.x >> p.y;
    sort(all(arr));

    auto [dis, ans] = closest_pair(arr);
    cout << arr[ans.ff].x << ' ' << arr[ans.ff].y << endl;
    cout << arr[ans.ss].x << ' ' << arr[ans.ss].y << endl;
    return 0;
}
