#include <cpplib/stdinc.hpp>

int n, k, ans[300][300];

void solve(int i, int j, int acc = 0){
    if(acc == n or !k)
        return;
    i %= n;
    j %= n;
    ans[i][j] = 1;
    k--;

    solve(i+1, j+1, acc+1);
}

int fA(int n){
    int mxr = 0, mir = LINF;
    for(int i=0; i<n; ++i){
        int cnt = 0;
        for(int j=0; j<n; ++j)
            cnt += ans[i][j];
        mxr = max(mxr, cnt);
        mir = min(mir, cnt);
    }
    int mxc = 0, mic = LINF;
    for(int i=0; i<n; ++i){
        int cnt = 0;
        for(int j=0; j<n; ++j)
            cnt += ans[j][i];
        mxc = max(mxc, cnt);
        mic = min(mic, cnt);
    }
    int r = mxr-mir, c = mxc-mic;
    return r*r + c*c;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        memset(ans, 0, sizeof(ans));
        for(int d=0; k>0; ++d)
            solve(d, 0);
        cout << fA(n) << endl;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j)
                cout << ans[i][j];
            cout << endl;
        }
    }
    return 0;
}
