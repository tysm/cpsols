#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vi ans;
        for(int i=n-1; i>=0; --i){
            if(b[i] == a[i])
                continue;
            if(i and b[i] == a[0]){
                ans.eb(1);
                a[0] = (a[0] == '0'? '1' : '0');
            }
            ans.eb(i+1);
            for(int j=0; j<=i; ++j)
                a[j] = (a[j] == '0'? '1' : '0');
            reverse(a.begin(), a.begin()+i+1);
        }
        cout << ans.size();
        if(ans.size())
            cout << ' ' << ans;
        cout << endl;
    }
    return 0;
}
