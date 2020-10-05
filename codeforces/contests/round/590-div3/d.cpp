#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/segment-tree.hpp>

int32_t main(){
    desync();
    string s;
    cin >> s;

    int n = s.size();
    vi arr(n);
    vector<SegTree<RSumQ, int> > v(26, SegTree<RSumQ, int>(n));
    for(int i=0; i<n; ++i){
        int c = s[i] - 'a';
        v[c].update(i, 1);
        arr[i] = c;
    }

    int q;
    cin >> q;
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int pos;
            char c;
            cin >> pos >> c;
            pos--;
            c -= 'a';

            int &cur = arr[pos];
            v[cur].update(pos, -1);

            v[c].update(pos, 1);

            cur = c;
        }
        else{
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int ans = 0;
            for(int i=0; i<26; ++i)
                ans += (v[i].query(l, r) > 0);
            cout << ans << endl;
        }
    }
    return 0;
}
