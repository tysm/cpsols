#include <cpplib/stdinc.hpp>

int32_t main(){
    ifstream cin("bugged.in");
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vi d(n);
        for(int &i:d)
            cin >> i;

        vi cnt(n);
        int ans = 0;
        for(int i=0; i<m; ++i){
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            cnt[a]--;
            cnt[b]++;
            ans += abs(d[a]-d[b]);
        }

        bool ok = true;
        for(int i=0; i<n; ++i){
            if(cnt[i] != 0)
                ok = false;
        }

        cout << (ok? ans : -1) << endl;
    }
    return 0;
}
