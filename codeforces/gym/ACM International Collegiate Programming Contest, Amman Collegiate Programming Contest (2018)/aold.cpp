#include <cpplib/stdinc.hpp>

int n;

int compute(int l, int r, vii &L, vii &R, vi &psum, int &auxl, int &auxr){
    int posl = lower_bound(all(R), ii(l, -1)) - R.begin();
    int posr = lower_bound(all(R), ii(r, -1)) - R.begin();
    auxl = posl;
    auxr = posr;

    if(posl == R.size())
        return 0;

    if(posl == posr){
        if(l >= L[posl].ff)
            return L[posl].ss*(r-l+1);
        else if(r >= L[posl].ff)
            return (r - L[posl].ff + 1)*L[posl].ss;
        return 0;
    }

    int res = 0;

    // L[posl] l R[posl]  ... r
    if(l >= L[posl].ff){
        int lr = R[posl].ff, v = L[posl].ss;
        res += (lr - l + 1)*v;
        posl++;
    }

    if(posr == R.size()) // R[n-1] ... r
        posr--;
    else if(r >= L[posr].ff){ // l ... L[posr] r R[posr]
        int rl = L[posr].ff, v = L[posr].ss;
        res += (r - rl + 1)*v;
        posr--;
    }

    if(posr >= posl)
        res += psum[posr] - (posl? psum[posl-1] : 0);
    return res;
}

void prox(int &l, int &r, int posl, int posr, vii &L, vii &R){
    if(posl >= n or l == L[n-1].ff){
        l = INF;
        r = INF;
        return;
    }

    int d = INF;

    if(l < L[posl].ff) // l L[posl] R[posl]
        d = min(d, L[posl].ff - l);
    else if(l != R[posl].ff){ // L[posl] l R[posl]
        d = min(d, R[posl].ff - l);
    }
    else if(posl < n-1) // R[posl]l L[posl+1]
        d = min(d, L[posl+1].ff - l);
    else{
        l = INF;
        r = INF;
        return;
    }

    if(posr < n){
        if(r < L[posr].ff)
            d = min(d, L[posr].ff - r);
        else if(r != R[posr].ff){
            d = min(d, R[posr].ff - r);
        }
        else if(posr < n-1){
            d = min(d, R[posr+1].ff - r);
        }
    }

    l += d;
    r += d;
}

int32_t main(){
    desync();
    int t;
    cin >> t;

    while(t--){
        int k;
        cin >> n >> k;

        vii L, R;
        for(int i=0; i<n; ++i){
            int l, r, v;
            cin >> l >> r >> v;
            L.eb(l, v);
            R.eb(r, v);
        }
        sort(all(L));
        sort(all(R));

        vi psum(n);
        for(int i=0; i<n; ++i){
            int l = L[i].ff, r = R[i].ff, v = L[i].ss;
            psum[i] = (r-l+1)*v;
            if(i)
                psum[i] += psum[i-1];
        }

        int l = 1, r = k, posl, posr, ans = 0;
        while(r <= 1e9 and l <= R[n-1].ff){
            int cur = compute(l, r, L, R, psum, posl, posr);
            ans = max(ans, cur);
            prox(l, r, posl, posr, L, R);
        }
        cout << ans << endl;
    }
    return 0;
}
