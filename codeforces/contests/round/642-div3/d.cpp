#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi ans(n);
        int acc = 0;
        set<pair<int, ii> > s;
        s.insert({-n, {0, n-1}});
        while(!s.empty()){
            auto it = s.begin();
            int l = it->ss.ff, r = it->ss.ss, mid = (l+r)/2;
            s.erase(it);

            ans[mid] = ++acc;

            int lr = mid-1, rl = mid+1;
            if(l <= lr)
                s.insert({-(lr-l+1), {l, lr}});
            if(rl <= r)
                s.insert({-(r-rl+1), {rl, r}});
        }
        for(int i=0; i<n; ++i){
            if(i)
                cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
