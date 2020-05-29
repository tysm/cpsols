#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/order-statistic-tree.hpp>

int32_t main(){
    desync();
    int n, m, q;
    cin >> n >> m >> q;
    map<int, ost_set<int> > l, c;
    while(q--){
        int op, x, y, s;
        char dir;
        cin >> op >> dir >> x >> y >> s;
        if(op == 1){
            bool valid = true;
            if(dir == 'L'){
                if(x+s-1 > m)
                    valid = false;
                for(int i=0; i<s and valid; ++i){
                    int k = l[y].order_of_key(x+i);
                    if(k == l[y].size())
                        continue;
                    else if(*l[y].find_by_order(k) == x+i)
                        valid = false;
                }
                if(valid){
                    for(int i=0; i<s; ++i){
                        l[y].insert(x+i);
                        c[x+i].insert(y);
                    }
                }
            }
            else{
                if(y+s-1 > n)
                    valid = false;
                for(int i=0; i<s and valid; ++i){
                    int k = c[x].order_of_key(y+i);
                    if(k == c[x].size())
                        continue;
                    else if(*c[x].find_by_order(k) == y+i)
                        valid = false;
                }
                if(valid){
                    for(int i=0; i<s; ++i){
                        l[y+i].insert(x);
                        c[x].insert(y+i);
                    }
                }
            }
            if(!valid)
                cout << -1 << endl;
        }
        else{
            int ans = 0;
            if(dir == 'L')
                ans = l[y].order_of_key(x+s) - l[y].order_of_key(x);
            else
                ans = c[x].order_of_key(y+s) - c[x].order_of_key(y);
            cout << ans << endl;
        }
    }
    return 0;
}
