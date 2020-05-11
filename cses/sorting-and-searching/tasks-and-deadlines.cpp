#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1630
    desync();
    int n;
    cin >> n;

    min_heap<ii> tasks;
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        tasks.push({a, b});
    }

    int ans = 0, t = 0;
    while(!tasks.empty()){
        ii cur = tasks.top(); tasks.pop();
        t += cur.ff;
        ans += cur.ss-t;
    }
    cout << ans << endl;
    return 0;
}
