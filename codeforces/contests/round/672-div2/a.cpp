#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vii vals;
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            vals.eb(x, i);
        }
        sort(all(vals));

        vi arr(n);
        for(int i=0; i<n; ++i)
            arr[vals[i].ss] = i;
        reverse(all(arr));
        cout << (is_sorted(all(arr))? "NO" : "YES") << endl;
    }
    return 0;
}
