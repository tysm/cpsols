#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>
#include <cpplib/data-structure/tree/order-statistic-tree.hpp>

bool valid(const ii &range, ost_set<int> &vis){
    return vis.order_of_key(range.ss) == vis.order_of_key(range.ff)+1;
}

int32_t main(){
    // https://cses.fi/problemset/task/1163
    desync();
    int x, n;
    cin >> x >> n;

    max_heap<pair<int, ii> > pq;
    ost_set<int> vis;
    vis.insert(0); vis.insert(x);
    pq.push({x, {0, x}});

    for(int i=0; i<n; ++i){
        int p;
        cin >> p;

        vis.insert(p);
        int idx = vis.order_of_key(p), prv = *vis.find_by_order(idx-1), nxt = *vis.find_by_order(idx+1);
        pq.push({p-prv, {prv, p}});
        pq.push({nxt-p, {p, nxt}});

        while(!valid(pq.top().ss, vis))
            pq.pop();
        if(i)
            cout << ' ';
        cout << pq.top().ff;
    }
    cout << endl;
    return 0;
}
