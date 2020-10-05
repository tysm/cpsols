#include <cpplib/stdinc.hpp>
#include <cpplib/adt/segtree.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    SegTree<RSumQ, int> st(arr);

    vvii R(n);
    for(int i=0; i<k; ++i){
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        R[r].eb(l, x);
    }

    bool ok = true;
    stack<int> pos;
    for(int i=0; i<n; ++i){
        if(arr[i] == 0){
            pos.ep(i);
            arr[i] = -1;
            st.update(i, -1);
        }

        sort(all(R[i]));
        for(auto [l, x] : R[i]){
            int cur = st.query(l, i);
            if(cur >= x)
                continue;

            int d = x-cur;
            while(d > 0 and !pos.empty() and pos.top() >= l){
                int idx = pos.top();
                pos.pop();

                arr[idx] = 1;
                st.update(idx, 2);

                d -= 2;
            }
            if(d > 0){
                ok = false;
                break;
            }
        }
        if(!ok)
            break;
    }
    if(!ok)
        cout << "Impossible" << endl;
    else
        cout << arr << endl;
    return 0;
}
