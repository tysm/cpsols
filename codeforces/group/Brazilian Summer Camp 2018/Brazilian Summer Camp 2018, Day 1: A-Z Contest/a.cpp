#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    point<int> arr[n];
    for(int i=0; i<n; ++i)
        cin >> arr[i].x >> arr[i].y;
    point<int> res;
    for(int i=0; i<n; ++i){
        int j = (i+1)%n;
        res += arr[i]^arr[j];
    }
    cout << fixed << setprecision(16) << norm(point<double>(res)/2) << endl;
    return 0;
}
