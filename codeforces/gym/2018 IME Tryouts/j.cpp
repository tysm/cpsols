#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/order-statistic-tree.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    ost_set<ii> ost;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        cout << n-ost.order_of_key({-x, i}) << endl;
        ost.insert({-x, i});
    }
    return 0;
}
