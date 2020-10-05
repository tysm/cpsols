#include <cpplib/stdinc.hpp>
#include <cpplib/adt/segtree.hpp>

int n;
vi arr;
map<int, vi> ocur;
SegTree<RMinQ, int> st(1);

int solve(int l, int r, int acc){
    int res = r-l+1, other = 0;

    int mval = st.query(l, r);
    other += mval-acc;

    int curl = l;
    int idx = lower_bound(all(ocur[mval]), l) - ocur[mval].begin();
    while(idx < ocur[mval].size() and ocur[mval][idx] <= r){
        if(curl <= ocur[mval][idx]-1)
            other += solve(curl, ocur[mval][idx]-1, mval);
        curl = ocur[mval][idx]+1;
        idx++;
    }
    if(curl <= r)
        other += solve(curl, r, mval);
    return min(res, other);
}


int32_t main(){
    desync();

    cin >> n;

    arr.resize(n);
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        ocur[arr[i]].eb(i);
    }
    st = SegTree<RMinQ, int>(arr);

    int ans = n, res = 0, curl = 0;
    for(int i=0; i<n; ++i){
        if(!arr[i]){
            ans--;
            if(curl <= i-1)
                res += solve(curl, i-1, 0);
            curl = i+1;
        }
    }
    if(curl <= n-1)
        res += solve(curl, n-1, 0);

    cout << min(ans, res) << endl;
    return 0;
}
