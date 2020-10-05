#include <cpplib/stdinc.hpp>
#include <cpplib/adt/heap.hpp>

const int m = 1e6;

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        set<int> vals;

        min_heap<ii> pq;
        for(int i=0; i<n; ++i){
            int l, r;
            cin >> l >> r;
            if(r < l){
                int l1 = 1, r1 = r, l2 = l, r2 = m;
                pq.ep(l1, r1);
                pq.ep(l2, r2);
                debug(l1, r1);
                debug(l2, r2);
                vals.ep(l1);
                vals.ep(r1);
                vals.ep(l2);
                vals.ep(r2);
            }
            else{
                pq.ep(l, r);
                vals.ep(l);
                vals.ep(r);
            }
        }

        int ans = 0;
        min_heap<int> cur;
        for(int i:vals){
            debug(i);
            while(!cur.empty() and cur.top() < i){
                debug(cur.top());
                cur.pop();
            }
            while(!pq.empty() and pq.top().ff == i){
                debug(pq.top());
                cur.ep(pq.top().ss);
                pq.pop();
            }
            ans = max((int)ans, (int)cur.size());
        }
        cout << ans << endl;
    }
    return 0;
}
