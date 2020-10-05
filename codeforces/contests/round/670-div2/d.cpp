#include <cpplib/stdinc.hpp>

int solve(int a0, int b0, int inc, int dec){
    int c0 = a0-b0, bn = b0 + inc, cn = c0 + dec;
    return max(c0, bn);
}

int ternary_search(int a0, int inc, int dec){
    int lo = -1e18, hi = 1e18;
    while(hi - lo > 2){
        int m1 = lo + (hi-lo)/3, m2 = hi - (hi-lo)/3;
        if(solve(a0, m1, inc, dec) > solve(a0, m2, inc, dec))
            lo = m1;
        else
            hi = m2;
    }

    int ans = solve(a0, lo, inc, dec);
    for(int i=lo+1; i<=hi; ++i)
        ans = min(ans, solve(a0, i, inc, dec));
    return ans;
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    vi d;
    for(int i=1; i<n; ++i)
        d.eb(arr[i]-arr[i-1]);

    int inc = 0, dec = 0;
    for(int i:d){
        if(i >= 0)
            inc += i;
        else
            dec += i;
    }

    cout << ternary_search(arr[0], inc, dec) << endl;

    int q;
    cin >> q;
    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;

        if(l){
            if(d[l-1] >= 0)
                inc -= d[l-1];
            else
                dec -= d[l-1];

            d[l-1] += k;

            if(d[l-1] >= 0)
                inc += d[l-1];
            else
                dec += d[l-1];
        }
        if(r < n-1){
            if(d[r] >= 0)
                inc -= d[r];
            else
                dec -= d[r];

            d[r] -= k;

            if(d[r] >= 0)
                inc += d[r];
            else
                dec += d[r];
        }

        if(l == 0)
            arr[0] += k;
        cout << ternary_search(arr[0], inc, dec) << endl;
    }
    return 0;
}
