#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        string a, t;
        cin >> a >> t;

        map<char, vi> ocur;
        for(int i=0; i<a.size(); ++i)
            ocur[a[i]].eb(i);

        int ok = true, ans = 1, cur = -1;
        for(int i=0; i<t.size(); ++i){
            char c = t[i];
            auto it = upper_bound(all(ocur[c]), cur);
            if(it == ocur[c].end()){
                ans++;
                if(ocur[c].empty()){
                    ok = false;
                    break;
                }
                cur = *ocur[c].begin();
            }
            else
                cur = *it;
        }
        if(ok)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
