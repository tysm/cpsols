#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(m > n)
            swap(n, m);
        n++;
        int m1 = m/2, m2 = m/2 + m%2;
        int ans = m1*(n/2+n%2) + m2*(n/2);
        cout << ans << endl;
    }
    return 0;
}
