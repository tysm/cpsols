#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>

int pos(SegTree<RSumQ, int> &st, int idx, int n){
    int lo = 0, hi = n-1;
    while(lo <= hi){
        int mid = (lo + hi)/2, i = mid - st.query(0, mid);
        if(i == idx){
            if(st.query(mid))
                hi = mid-1;
            else
                return mid;
        }
        else if(i < idx)
            lo = mid+1;
        else
            hi =  mid-1;
    }
}

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    map<char, set<int> > cpos;
    for(int i=0; i<n; ++i)
        cpos[s[i]].insert(i);
    SegTree<RSumQ, int> st(n);
    while(q--){
        int a, b;
        char c;
        cin >> a >> b >> c;
        int i = pos(st, a-1, n), j = pos(st, b-1, n);
        vi rem;
        auto itb = cpos[c].lower_bound(i), ite = cpos[c].upper_bound(j);
        for(auto it=itb; it!=ite; ++it)
            rem.pb(*it);
        for(int idx:rem){
            st.update(idx, 1);
            cpos[c].erase(idx);
        }
    }
    for(int i=0; i<n; ++i){
        if(!st.query(i))
            cout << s[i];
    }
    cout << endl;
    return 0;
}
