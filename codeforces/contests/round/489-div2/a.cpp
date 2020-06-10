#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    set<int> ans;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        if(x)
            ans.insert(x);
    }
    cout << ans.size() << endl;
    return 0;
}
