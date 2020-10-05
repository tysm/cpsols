#include <cpplib/stdinc.hpp>
#include <cpplib/adt/polynomial.hpp>

int32_t main(){
    desync();
    int n, x, y;
    cin >> n >> x >> y;

    vi arr(n+1);
    for(int &i:arr)
        cin >> i;

    vi a(x+1), b(x+1);
    for(int i:arr){
        a[i] = 1;
        b[x-i] = 1;
    }
    polyn<int> A(a), B(b);
    A *= B;

    vi dp(MAXN, -1);
    for(int i=0; i<A.size(); ++i){
        if(!A[i])
            continue;

        if(i-x >= 1){
            int j = 2*(i-x + y);
            if(j < MAXN)
                dp[j] = j;
        }
    }
    for(int l=1; l<MAXN; ++l){
        if(dp[l] == -1)
            continue;
        for(int i=l; i<MAXN; i+=l)
            dp[i] = max(dp[i], dp[l]);
    }

    int q;
    cin >> q;
    while(q--){
        int l;
        cin >> l;
        cout << dp[l] << " \n"[!q];
    }
    return 0;
}
