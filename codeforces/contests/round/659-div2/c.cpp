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
        bool valid = true;
        for(int i=0; i<n; ++i){
            if(a[i] == b[i])
                continue;
            if(b[i]-'a' >= 20 or b[i] < a[i])
                valid = false;
        }
        if(!valid){
            cout << -1 << endl;
            continue;
        }
        vi cnt(26), nxt(26, LINF);
        for(int i=0; i<n; ++i){
            if(a[i] == b[i])
                continue;
            int j = a[i] - 'a', k = b[i] - 'a';
            cnt[j]++;
            nxt[j] = min(nxt[j], k);
        }
    }
    return 0;
}
