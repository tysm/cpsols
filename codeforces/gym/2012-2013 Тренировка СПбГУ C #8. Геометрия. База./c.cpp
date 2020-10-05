#include <cpplib/stdinc.hpp>
#include <cpplib/adt/geoinc.hpp>

int32_t main(){
    desync();
    freopen("area.in", "r", stdin);
    freopen("area.out", "w", stdout);
    int n;
    cin >> n;
    vector<point<int> > arr(n);
    for(auto &i:arr)
        cin >> i.x >> i.y;
    polygon<int> pl(arr);
    cout << fixed << setprecision(16) << pl.area() << endl;
    return 0;
}
