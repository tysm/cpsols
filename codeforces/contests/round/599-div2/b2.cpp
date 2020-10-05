#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        string a, b;
        cin >> n >> a >> b;
        vi cnt(26);
        for(char c:(a+b))
            cnt[c-'a']++;
        bool ok = true;
        for(int i:cnt){
            if(i%2)
                ok = false;
        }
        cout << (ok? "Yes" : "No") << endl;
        if(ok){
            vii ops;
            for(int i=0; i<n; ++i){
                if(a[i] == b[i])
                    continue;
                for(int j=i+1; j<n; ++j){
                    if(a[i] == a[j]){
                        swap(a[j], b[i]);
                        ops.eb(j+1, i+1);
                        break;
                    }
                    if(a[i] == b[j]){
                        swap(a[j], b[j]);
                        ops.eb(j+1, j+1);
                        swap(a[j], b[i]);
                        ops.eb(j+1, i+1);
                        break;
                    }
                }
            }
            debug(a);
            debug(b);
            cout << ops.size() << endl;
            for(auto [i, j]:ops)
                cout << i << ' ' << j << endl;
        }
    }
    return 0;
}
