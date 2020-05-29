#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    vi diff(n);
    for(int i=1; i<n; ++i)
        diff[i] = abs(arr[i] - arr[i-1]);
    SegTreeS<RMaxQ, int> st(diff);

    int q;
    cin >> q;
    while(q--){
        int op, idx, x;
        cin >> op >> idx >> x;
        idx--;
        if(op == 1){
            arr[idx] = x;
            if(idx)
                st.set(idx, abs(arr[idx] - arr[idx-1]));
            if(idx < n-1)
                st.set(idx+1, abs(arr[idx+1] - arr[idx]));
        }
        else{
            if(n == 1){
                cout << 1 << endl;
                continue;
            }
            int lo = idx+1, hi = n-1, ans = idx;
            while(lo <= hi){
                int mid = (lo + hi)/2;
                // debug(mid);
                if (st.query(lo, mid) <= x){
                    ans = mid;
                    lo = mid+1;
                }
                else
                    hi = mid-1;
            }
            cout << ans + 1 << endl;
        }
    }
    return 0;
}
