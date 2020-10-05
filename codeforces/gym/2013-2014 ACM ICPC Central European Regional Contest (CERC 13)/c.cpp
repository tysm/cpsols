#include <cpplib/stdinc.hpp>
#include <cpplib/math/euclid.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vi arr(n);
        for(int &i:arr)
            cin >> i;

        int ans = 0;
        vector<set<int> > sts(n);
        for(int i=0; i<n; ++i){
            int g = arr[i];
            for(int j=i; j<n; ++j){
                g = gcd(g, arr[j]);
                if(sts[j].count(g))
                    break;
                ans = max(ans, g*(j-i+1));
                sts[j].ep(g);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
