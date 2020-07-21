#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    freopen("area.in", "r", stdin);
    freopen("area.out", "w", stdout);
    int n;
    cin >> n;
    vector<point<int> > arr(n);
    for(auto &i:arr)
        cin >> i.x >> i.y;
    double ans = 0;
    for(int i = 0, j = 1; i < n; ++i, j = (j+1)%n)
        ans += norm(arr[i]^arr[j])*get<2>(orientation(arr[i], arr[j]));
    cout << fixed << setprecision(16) << abs(ans)/2 << endl;
    return 0;
}
