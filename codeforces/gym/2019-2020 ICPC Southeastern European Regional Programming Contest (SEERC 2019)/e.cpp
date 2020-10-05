#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    int lc, pc, lm, pm;
    cin >> lc >> pc >> lm >> pm;

    int t, d;
    cin >> t >> d;

    vi arr(n);
    for(int &i:arr)
        cin >> i;
    sort(rall(arr));

    int acc = 0;
    vi ascar(n), asmot(n);
    for(int i=0; i<n; ++i){
        ascar[i] += max((int)0, lc-arr[i]);
        asmot[i] += max((int)0, lm-arr[i]);
        acc += min(d, max((int)0, arr[i]-lm));
    }

    vi pscar(ascar), psmot(asmot);
    for(int i=1; i<n; ++i){
        pscar[i] += pscar[i-1];
        psmot[i] += psmot[i-1];
    }

    int ans = INF, r=n-1;
    for(int c=0; c<=n; ++c){
        int l = c;
        if(c){
            if(r >= c-1){
                acc -= min(d, max((int)0, arr[c-1]-lm));
                acc += min(d, max((int)0, arr[c-1]-lc));
                for(int x=r; x>r-(k-1) and x>=l; --x){
                    acc -= min(d, max((int)0, arr[x]-lm));
                    acc += min(d, arr[x]-1);
                }
            }
            r -= k-1;
        }

        int cost = 0;
        if(c)
            cost += pscar[c-1];

        if(l <= r){
            cost += psmot[r];
            if(l)
                cost -= psmot[l-1];
        }
        if(cost <= acc){
            cost *= t;
            cost += c*pc;
            if(l <= r)
                cost += (r-l+1)*pm;
            ans = min(ans, cost);
        }
        if(r < l)
            break;
    }

    if(ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
