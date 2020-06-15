#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi ans(2);
        cin >> ans[0] >> ans[1];
        for(int i=2; i<n; ++i){
            int x;
            cin >> x;
            bool inc = (ans.back() - ans[ans.size()-2] > 0);
            if(inc){
                if(x > ans.back())
                    ans.pop_back();
                ans.pb(x);
            }
            else{
                if(x < ans.back())
                    ans.pop_back();
                ans.pb(x);
            }
        }
        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); ++i){
            if(i)
                cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
