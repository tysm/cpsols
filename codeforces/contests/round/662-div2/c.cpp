#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi cnt(n+1);
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            cnt[x]++;
        }
        sort(rall(cnt));
        int acc = 0, val = cnt[0];
        for(int i=0; i<=n; ++i){
            if(cnt[i] == val)
                acc++;
        }
        if(val == 2 and acc == 1)
            cout << n-2 << endl;
        else{
            debug(n/val);
            debug(n/acc);
        }
    }
    return 0;
}
