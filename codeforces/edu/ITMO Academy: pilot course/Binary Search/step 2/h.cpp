#include <cpplib/stdinc.hpp>

bool check(vi &knd, vi val, vi &cst, int r, int k){
    for(int i:knd){
        if(val[i] >= k)
            val[i] -= k;
        else{
            int aux = k-val[i];
            val[i] = 0;
            if(r < aux*cst[i])
                return false;
            r -= aux*cst[i];
        }
    }
    return true;
}

int32_t main(){
    desync();
    string s;
    cin >> s;

    vi knd, val(3), cst(3);
    for(char c:s){
        if(c == 'B')
            knd.eb(0);
        else if(c == 'S')
            knd.eb(1);
        else
            knd.eb(2);
    }

    for(int &i:val)
        cin >> i;
    for(int &i:cst)
        cin >> i;

    int r;
    cin >> r;

    int lo = 0, hi = 2e12, ans = 0;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(check(knd, val, cst, r, mid)){
            ans = mid;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    cout << ans << endl;
    return 0;
}
