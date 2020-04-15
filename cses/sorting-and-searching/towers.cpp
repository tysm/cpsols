#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1073
    desync();
    int n;
    cin >> n;
    multiset<int> tw;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        if(auto it = tw.upper_bound(x); it != tw.end())
            tw.erase(it);
        tw.insert(x);
    }
    cout << tw.size() << endl;
    return 0;
}
