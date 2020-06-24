#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>
#include <cpplib/data-structure/tree/order-statistic-tree.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    vii ranges(1);
    for(int i=1; i<n; ++i){
        if(arr[i] == arr[i-1])
            ranges.back().ss = i;
        else
            ranges.pb({i, i});
    }
    ost_set<pair<ii, int> > dirty;
    max_heap<pair<int, ii> > q;
    for(ii &i:ranges){
        int cnt = i.ss-i.ff+1;
        dirty.insert({i, cnt});
        ii j = {-i.ff, -i.ss};
        q.push({cnt, j});
    }
    int ans = 0;
    while(!q.empty()){
        int cnt = q.top().ff;
        ii j = q.top().ss;
        q.pop();
        ii i = {-j.ff, -j.ss};
        pair<ii, int> key = {i, cnt};
        if(dirty.find(key) == dirty.end())
            continue;
        ans++;
        int cur = dirty.order_of_key(key), prv = cur-1, nxt = cur+1;
        if(prv >= 0 and nxt < dirty.size()){
            pair<ii, int> pr = *dirty.find_by_order(prv), nr = *dirty.find_by_order(nxt);
            if(arr[pr.ff.ff] == arr[nr.ff.ff]){
                dirty.erase(pr);
                dirty.erase(nr);
                dirty.insert({{pr.ff.ff, nr.ff.ss}, pr.ss + nr.ss});
                q.push({pr.ss + nr.ss, {-pr.ff.ff, -nr.ff.ss}});
            }
        }
        dirty.erase(key);
    }
    cout << ans << endl;
    return 0;
}
