#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int mcut = 0;
        set<int> cut;
        int ans = -1;
        for(int i=0; i<n; ++i){
            int d, h;
            cin >> d >> h;
            if(d >= x)
                ans = 1;
            else
                cut.emplace(d);
            mcut = max(mcut, d-h);
        }
        if(ans == -1 and mcut){
            ans = LINF;
            for(int p:cut){
                int r = x-p;
                ans = min(ans, 1+r/mcut+(r%mcut != 0));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
