#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1644
    desync();
    int n, a, b;
    cin >> n >> a >> b;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    vi psum(arr);
    for(int i=1; i<n; ++i)
        psum[i] += psum[i-1];

    int ans = -INF*MAX;
    min_heap<ii> lsum; lsum.push({0, -1});
    for(int i=a-1; i<n; ++i){
        while(lsum.top().ss < i-b)
            lsum.pop();
        ans = max(ans, psum[i] - lsum.top().ff);
        lsum.push({psum[i-a+1], i-a+1});
    }
    cout << ans << endl;
}
