#include <cpplib/stdinc.hpp>

int32_t main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vii seg;
    int acc = 0, l = -1;
    for(int i=0; i<n; ++i){
        if(s[i] == 'G'){
            if(l == -1)
                l = i;
            acc++;
        }
        else{
            if(l != -1){
                seg.eb(l, i-1);
                l = -1;
            }
        }
    }
    if(l != -1){
        seg.eb(l, n-1);
        l = -1;
    }
    int ans = 0;
    n = seg.size();
    for(int i=0; i<n; ++i){
        int l = seg[i].ff, r = seg[i].ss, len = r-l+1;
        ans = max(ans, len + (acc != len));
        if(i < n-1){
            int ln = seg[i+1].ff, rn = seg[i+1].ss, nlen = rn-ln+1;
            if(ln-r != 2)
                continue;
            ans = max(ans, len + nlen + (acc != len + nlen));
        }
    }
    cout << ans << endl;
    return 0;
}
