#include <cpplib/header.hpp>
#include <cpplib/data-structures/trees/order-statistic-tree.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1749
    desync();
    int n;
    cin >> n;
    
    ost_set<ii> oset;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        oset.insert({i, x});
    }

    for(int i=0; i<n; ++i){
        int id;
        cin >> id;
        if(i)
            cout << ' ';
        cout << oset.find_by_order(id-1)->ss;
        oset.erase(oset.find_by_order(id-1));
    }
    cout << endl;
    return 0;
}
