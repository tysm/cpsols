#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<point<int> > arr(n);
        for(auto &i:arr)
            cin >> i.x >> i.y;
        sort(rall(arr));
        if(n <= 1){
            cout << 0 << endl;
            continue;
        }
        double ans = distance(arr[0], arr[1]);
        int i = 1, r = 2;
        line<int> l(arr[i], point<int>(1, 0));
        while(r < n){
            while(arr[r].y <= arr[i].y and r < n)
                r++;
            if(r == n)
                break;
            segment<int> s(arr[r-1], arr[r]);
            ans += distance(intersection(s, l).a, arr[r]);
            i = r;
            l = {arr[i], point<int>(1, 0)};
            r++;
        }
        cout << fixed << setprecision(16) << ans << endl;
    }
    return 0;
}
