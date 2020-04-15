#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1621
    desync();
    int n;
    cin >> n;
    set<int> s;
    while(n--){
        int a;
        cin >> a;
        s.emplace(a);
    }
    cout << s.size() << endl;
    return 0;
}
