#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1642
    desync();
    int n, k;
    cin >> n >> k;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    set<pair<int, ii> > sum2;
    for(int c=0; c<n-1; ++c){
        for(int d=c+1; d<n; ++d)
            sum2.insert({arr[c]+arr[d], {c, d}});
    }

    bool possible = false;
    for(int a=0; a<n-3 and !possible; ++a){
        for(int b=a+1; b<n-2 and !possible; ++b){
            int sum = arr[a] + arr[b];
            if(sum >= k)
                continue;
            int r = k-sum;
            auto it = sum2.lower_bound({r, {b+1, b+1}});
            if(it == sum2.end() or it->ff > r)
                continue;
            cout << a+1 << ' ' << b+1 << ' ' << it->ss.ff+1 << ' ' << it->ss.ss+1 << endl;
            possible = true;
        }
    }
    if(!possible)
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
