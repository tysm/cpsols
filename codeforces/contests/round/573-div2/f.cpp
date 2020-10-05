#include <cpplib/stdinc.hpp>
#include <cpplib/adt/heap.hpp>
#include <cpplib/adt/ost.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    ost_set<int> aux;
    map<int, int> cnt;
    min_heap<ii> pq;
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        aux.insert(x);
        cnt[x]++;
        pq.ep(y, x);
    }

    int ans = 0, ly = -1, lx = -1;
    while(!pq.empty()){
        auto [y, x] = pq.top();
        pq.pop();

        if(y != ly)
            lx = -1;

        int acc = aux.order_of_key(lx) + (cnt[lx] > 0);

        int l = aux.order_of_key(x)+1, r = aux.size()-l+1;
        l -= acc;
        ans += l*r;

        cnt[x]--;
        if(cnt[x] == 0){
            cnt.erase(x);
            aux.erase(x);
        }

        ly = y;
        lx = x;
    }
    cout << ans << endl;
    return 0;
}
