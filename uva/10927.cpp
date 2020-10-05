#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/geo/sort.hpp>

// point<int> origin//, x_axis(1, 0), z_axis(0, 0, 1);

// int quad(const point<int> &p){
//     if(p.x >= 0)
//         return p.y >= 0? 1 : 4;
//     else
//         return p.y >= 0? 2 : 3;
//     assert(false);
// }

// bool cmp(const point<int> &i, const point<int> &j){
//     if(quad(i) < quad(j))
//         return true;
//     else if(quad(i) <= quad(j)){
//         int o = get<2>(orientation(i, j));
//         if(o > 0)
//             return true;
//         else if(o == 0)
//             return squared_norm(point<int>(i.x, i.y)) < squared_norm(point<int>(j.x, j.y));
//     }
//     return false;
// }

int32_t main(){
    desync();
    int n, t = 0;
    while(cin >> n, n){
        vector<point<int> > arr(n);
        for(auto &i:arr)
            cin >> i.x >> i.y >> i.z;
        polar_sort(arr);
        vector<point<int> > ans;
        for(int i=0, j=1; j < n; ++j){
            point<int> pi(arr[i].x, arr[i].y), pj(arr[j].x, arr[j].y);
            if(!parallel(pi, pj) or arr[i].z < arr[j].z)
                i = j;
            else
                ans.eb(arr[j]);
        }
        cout << "Data set " << ++t << ':' << endl;
        if(ans.empty())
            cout << "All the lights are visible." << endl;
        else{
            cout << "Some lights are not visible:" << endl;
            sort(all(ans));
            for(int i=0; i<ans.size(); ++i)
                cout << "x = " << ans[i].x << ", y = " << ans[i].y << ";."[i+1 == ans.size()] << endl;
        }
    }
    return 0;
}
