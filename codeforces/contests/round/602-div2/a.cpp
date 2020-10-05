#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi l(n), r(n);
        for(int i=0; i<n; ++i)
            cin >> l[i] >> r[i];
        sort(rall(l));
        sort(all(r));
        cout << max((int)0, l[0]-r[0]) << endl;
    }
    return 0;
}
