#include <cpplib/stdinc.hpp>

bool lxsml(vii &arr, int l1, int r1, int l2, int r2){
    for(int i=l1, j=l2; i<=r1 and j<=l2; ++i, ++j){
        if(arr[i].ff < arr[j].ff)
            return true;
        else if(arr[j].ff < arr[i].ff)
            return false;
    }
    return false;
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    vii arr;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        arr.eb(x, i);
    }
    sort(all(arr), [](ii &i, ii &j){ return tie(i.ff, j.ss) < tie(j.ff, i.ss); });

    vi psum(n);
    for(int i=0; i<n; ++i){
        psum[i] = arr[i].ff;
        if(i)
            psum[i] += psum[i-1];
    }

    int q;
    cin >> q;
    while(q--){
        int k, j;
        cin >> k >> j;
        j--;

        int l = 0, sum = psum[k-1];
        for(int r=k; r<n; ++r){
            int nsum = psum[r] - psum[r-k];
            if(nsum > sum or nsum == sum and lxsml(arr, r-k+1, r, l, l+k-1)){
                sum = nsum;
                l = r-k+1;
            }
        }
        vii cur;
        for(int i=l; i<l+k; ++i)
            cur.eb(arr[i]);
        sort(all(cur), [](ii &i, ii &j){ return i.ss < j.ss; });
        cout << cur[j].ff << endl;
    }
    return 0;
}
