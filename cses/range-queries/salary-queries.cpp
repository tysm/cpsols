#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/order-statistic-tree.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1144
    desync();
    int n, q;
    cin >> n >> q;

    vi p(n);
    ost_set<ii> ost;
    for(int i=0; i<n; ++i){
        cin >> p[i];
        ost.insert({p[i], i});
    }

    while(q--){
        char op;
        cin >> op;
        switch(op){
            case '!':
                int k, x;
                cin >> k >> x;
                k--;
                ost.erase({p[k], k});
                p[k] = x;
                ost.insert({x, k});
                break;
            case '?':
                int a, b;
                cin >> a >> b;
                cout << ost.order_of_key({b, n}) - ost.order_of_key({a, 0}) << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
