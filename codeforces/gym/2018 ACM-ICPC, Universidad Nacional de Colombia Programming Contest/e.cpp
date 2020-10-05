#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/adt/segment.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    point<double> o(0, 0);
    vector<point<double> > arr;
    for(int i=n; i>=0; --i){
        for(int j=0; j<=i; ++j)
            arr.eb(o + point<int>(1, 0)*j);
        o += rotate(point<int>(1, 0), point<int>(0, 0, 1), PI/3);
    }

    int m = arr.size(), ans = 0;
    for(int i=0; i<m; ++i){
        for(int j=i+1; j<m; ++j){
            segment<double> s(arr[i], arr[j]);
            for(int k=0; k<m; ++k){
                if(k == i or k == j)
                    continue;
                if(count(s, arr[k])){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
