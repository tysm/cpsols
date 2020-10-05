#include <cpplib/stdinc.hpp>

bool comp(ii &a, ii &b){
    return a.ff > b.ff and a.ss < b.ss;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vii arr(n);
        for(ii &i:arr){
            int a, b;
            char c;
            cin >> a >> c >> b;
            i.ff = a*10 + b;
            cin >> a >> c >> b;
            i.ss = a*10 + b;
        }
        int ans = 1;
        vi d(n, 1);
        for(int i=0; i<n; ++i){
            ii &a = arr[i];
            for(int j=0; j<i; ++j){
                ii &b = arr[j];
                if(comp(a, b))
                    d[i] = max(d[i], d[j]+1);
            }
            ans = max(d[i], ans);
        }
        cout << ans << endl;
    }
    return 0;
}
