#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

pair<int, vi> solve(vector<pair<ii, int> > &arr){
    int cnt = 0;
    vi ans(arr.size());

    min_heap<int> empty;
    min_heap<ii> full;
    for(pair<ii, int> cus:arr){
        int i = cus.ss, a = cus.ff.ff, b = cus.ff.ss;
        while(!full.empty() and full.top().ff < a){
            empty.push(full.top().ss);
            full.pop();
        }
        if(empty.empty())
            empty.push(++cnt);
        ans[i] = empty.top();
        full.push({b, empty.top()});
        empty.pop();
    }

    return {cnt, ans};
}

int32_t main(){
    // https://cses.fi/problemset/task/1164
    desync();
    int n;
    cin >> n;
    vector<pair<ii, int> > arr;
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        arr.pb({{a, b}, i});
    }
    sort(arr.begin(), arr.end());

    pair<int, vi> ans = solve(arr);

    cout << ans.ff << endl;
    for(int i=0; i<n; ++i){
        if(i)
            cout << ' ';
        cout << ans.ss[i];
    }
    cout << endl;
    return 0;
}
