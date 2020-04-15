#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1091
    desync();
    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for(int i=0; i<n; ++i){
        int t;
        cin >> t;
        tickets.insert(-t);
    }

    for(int i=0; i<m; ++i){
        int p;
        cin >> p;
        auto t = tickets.lower_bound(-p);
        if(t != tickets.end()){
            cout << -(*t) << endl;
            tickets.erase(t);
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
