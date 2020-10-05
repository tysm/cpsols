#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, d, m;
    cin >> n >> d >> m;

    vi A, B;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        if(x > m)
            A.eb(x);
        else
            B.eb(x);
    }
    sort(rall(A));
    sort(rall(B));

    vi pa(A), pb(B);
    for(int i=1; i<A.size(); ++i)
        pa[i] += pa[i-1];
    for(int i=1; i<B.size(); ++i)
        pb[i] += pb[i-1];

    int ans = 0;
    for(int i=0; i<=B.size(); ++i){
        int k = n-i, res = (i? pb[i-1] : 0);
        int mz = k/(d+1) + (k%(d+1) > 0);
        if(mz > A.size())
            continue;
        if(mz)
            res += pa[mz-1];
        ans = max(res, ans);
    }
    cout << ans << endl;
    return 0;
}
