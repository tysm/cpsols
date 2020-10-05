#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vii a, b;
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            if(x < 0)
                a.eb(x, i);
            else
                b.eb(x, i);
        }
        int i=0, j=0;
        while(i < a.size() and j < b.size()){
            while(i < a.size() and b[j].ss > a[i].ss)
                i++;
            if(i == a.size())
                break;
            int d = min(-a[i].ff, b[j].ff);
            b[j].ff -= d;
            a[i].ff += d;
            if(a[i].ff == 0)
                i++;
            if(b[j].ff == 0)
                j++;
        }
        int ans = 0;
        for(int i=0; i<a.size(); ++i)
            ans += -a[i].ff;
        cout << ans << endl;
    }
    return 0;
}
