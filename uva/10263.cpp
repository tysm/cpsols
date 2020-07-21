#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    point<double> m;
    while(cin >> m.x >> m.y){
        int n;
        cin >> n;
        vector<point<double> > arr(n+1);
        for(auto &i:arr)
            cin >> i.x >> i.y;
        point<double> ans = arr[0];
        for(int i=1; i<=n; i++){
            auto p = closest(m, segment<int>(arr[i-1], arr[i]));
            if(distance(p, m) <= distance(ans, m))
                ans = p;
        }
        cout << fixed << setprecision(4) << ans.x << endl << ans.y << endl;
    }
    return 0;
}
