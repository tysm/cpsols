#include <cpplib/stdinc.hpp>

int n;
vii arr;
vvi dp, rg;

int solve(int l, int r){
    if(l > r)
        return 0;
    int &res = dp[l][r];
    if(res != -1)
        return res;

    res = solve(l+1, r);
    for(int ri:rg[l]){
        if(ri >= r)
            continue;
        res = max(res, solve(l, ri)+solve(ri+1, r));
    }
    res += count(all(rg[l]), r);
    return res;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        arr = vii(n);
        vi vals;
        map<int, int> cmp;
        for(ii &i:arr){
            cin >> i.ff >> i.ss;
            vals.eb(i.ff);
            vals.eb(i.ss);
        }
        sort(all(vals));
        int k=0;
        for(int v:vals){
            if(cmp.count(v))
                continue;
            cmp[v] = k++;
        }
        for(ii &i:arr){
            i.ff = cmp[i.ff];
            i.ss = cmp[i.ss];
        }
        dp = vvi(k, vi(k, -1));
        rg = vvi(k);
        for(ii &i:arr)
            rg[i.ff].eb(i.ss);
        cout << solve(0, k-1) << endl;
    }
    return 0;
}
