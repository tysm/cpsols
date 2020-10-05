#include <cpplib/stdinc.hpp>

int n, k, l;
vi arr(101), p;

int dp[101][201];

bool solve(int idx, int t){
    t = t%(2*k);
    if(idx == n)
        return true;
    int &res = dp[idx][t];
    if(res == -1){
        res = 0;
        if(arr[idx] + p[t] <= l)
            res = solve(idx+1, t+1) or solve(idx, t+1);
    }
    return res;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k >> l;
        for(int i=0; i<n; ++i){
            cin >> arr[i];
            for(int j=0; j<2*k; ++j)
                dp[i][j] = -1;
        }

        p = vi(2*k);
        iota(p.begin(), p.begin()+k, 0);
        iota(p.rbegin(), p.rbegin()+k, 1);

        bool valid = false;
        for(int i=0; i<2*k; ++i)
            valid |= solve(0, i);
        for(int i=0; i<n; ++i){
            vi aux;
            for(int t=0; t<2*k; ++t)
                aux.eb(dp[i][t]);
            cout << aux << endl;
        }

        cout << (valid? "Yes" : "No") << endl;
    }
    return 0;
}
