#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    map<int, int> cnt;
    int acc = 0, mval;
    for(int i=0; i<=63; i++){
        if(n & ((int)1<<i)){
            cnt[i]++;
            acc++;
            mval = i;
        }
    }
    while(acc < k){
        acc++;
        cnt[mval]--;
        cnt[mval-1] += 2;
        if(!cnt[mval])
            mval--;
    }
    if(acc > k)
        cout << "NO" << endl;
    else{
        int sval = LINF;
        for(ii i:cnt){
            if(i.ss)
                sval = min(sval, i.ff);
        }
        mval--;
        while(cnt[mval] >= 2){
            if(mval == sval and cnt[mval] < 3)
                break;
            cnt[mval] -= 2;
            cnt[mval+1]++;
            cnt[sval]--;
            cnt[sval-1]+=2;
            sval--;
        }
        cout << "YES" << endl;
        vi res;
        for(ii i:cnt){
            for(int j=0; j<i.ss; ++j)
                res.eb(i.ff);
        }
        sort(rall(res));
        cout << res << endl;
    }
    return 0;
}
