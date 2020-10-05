#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int x;
        cin >> x;

        int n = s.size();
        vi ans(n, -1);

        bool ok = true;
        for(int i=0; i<n; ++i){
            if(s[i] == '1'){
                if(i-x >= 0 and ans[i-x] != 0)
                    ans[i-x] = 1;
                else if(i+x < n and ans[i+x] != 0)
                    ans[i+x] = 1;
                else
                    ok = false;
            }
            else{
                if(i-x >= 0){
                    if(ans[i-x] > 0)
                        ok = false;
                    ans[i-x] = 0;
                }
                if(i+x < n){
                    if(ans[i+x] > 0)
                        ok = false;
                    ans[i+x] = 0;
                }
            }
        }
        if(!ok)
            cout << -1 << endl;
        else{
            for(int i:ans)
                cout << max((int)0, i);
            cout << endl;
        }
    }
    return 0;
}
