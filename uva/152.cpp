#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geometry/point.hpp>

int32_t main(){
    desync();
    vector<point<int> > arr;
    point<int> p;
    cin >> p.x >> p.y >> p.z;
    while(!p.is_null()){
        arr.eb(p);
        cin >> p.x >> p.y >> p.z;
    }
    int n = arr.size(), ans[10] = {};
    for(int i=0; i<n; ++i){
        double d = 11;
        for(int j=0; j<n; ++j){
            if(j == i)
                continue;
            d = min(d, distance(arr[i], arr[j]));
        }
        for(int j=1; j<=10; ++j){
            if(d < j){
                ans[j-1]++;
                break;
            }
        }
    }
    for(int i=0; i<10; ++i){
        auto aux = to_string(ans[i]);
        for(int j=4; j>aux.size(); --j)
            cout << ' ';
        cout << aux;
    }
    cout << endl;
    return 0;
}
