#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1745
    desync();
    int n;
    cin >> n;

    bitset<MAX> bts;
    bts.set(0);

    vi ans;
    for(int i=0; i<n; ++i){
        int c;
        cin >> c;
        for(int j=MAX-1; j>0 and j-c>=0; --j){
            if(bts[j])
                continue;
            if(bts[j-c]){
                bts.set(j);
                ans.pb(j);
            }
        }
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); ++i){
        if(i)
            cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
