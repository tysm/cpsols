#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>

int n;
string a, b;
vi ans;
SegTree<RSumQ, int> st(1);

void solve(int bi, int ai, int r){
    if(bi < 0)
        return;
    bool inv = st.query(ai)%2;
    char av = ((a[ai]-'0')+inv)%2 + '0';
    if(av == b[bi]){
        if(ai <= r)
            ai++;
        else
            ai--;
    }
    else{
        if(ai != r){
            bool rinv = st.query(r)%2;
            char rv = ((a[r]-'0')+inv)%2 + '0';
            if(b[bi] == rv){
                ans.eb(1);
                st.update(r, 1);
            }
        }
        ans.eb(abs(ai-r)+1);
        if(ai <= r){
            st.update(ai, r, 1);
            r--;
        }
        else{
            st.update(r, ai, 1);
            r++;
        }
        swap(ai, r);
    }
    solve(bi-1, ai, r);
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        ans.clear();
        cin >> n;
        cin >> a >> b;
        st = SegTree<RSumQ, int>(n);
        solve(n-1, n-1, 0);

        cout << ans.size();
        if(ans.size())
            cout << ' ' << ans;
        cout << endl;
    }
    return 0;
}
