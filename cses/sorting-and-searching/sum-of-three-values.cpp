#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1641/
    desync();
    int n, k;
    cin >> n >> k;
    vii arr;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        arr.pb({x, i});
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n-2; ++i){
        int a = arr[i].ff;
        for(int j=i+1; j<n-1; ++j){
            int b = arr[j].ff, c = k-(a+b);
            if(c <= 0)
                break;
            auto it = lower_bound(arr.begin()+j+1, arr.end(), ii(c, -1));
            if(it == arr.end() or it->ff != c)
                continue;
            debug(a);
            debug(b);
            debug(c);
            debug(it->ff);
            cout << arr[i].ss+1 << ' ' << arr[j].ss+1 << ' ' << it->ss+1 << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
