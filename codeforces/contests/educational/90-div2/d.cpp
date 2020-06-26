#include <cpplib/stdinc.hpp>

int n, arr[212345], dp[4][112345];

int solve(int idx, int st){
    if(idx*2 >= n)
        return 0;
    int &res = dp[st][idx];
    if(res == -1){
        int i = idx*2, j = i+1;
        if(st == 0){
            res = arr[i] + solve(idx+1, 0);
            if(j < n){
                res = max(res, arr[j] + solve(idx+1, 1));
                if(j != n-1)
                    res = max(res, arr[i] + arr[j] + solve(idx+1, 2));
            }
        }
        else if(st == 1){
            res = arr[i] + solve(idx+1, 3);
            if(j < n)
                res = max(res, arr[j] + solve(idx+1, 1));
        }
        else if(st == 2){
            res = solve(idx+1, 3);
            if(j < n and j != n-1)
                res = max(res, arr[j] + solve(idx+1, 2));
        }
        else
            res = arr[i] + solve(idx+1, 3);
    }
    return res;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; ++i){
            cin >> arr[i];
            for(int st=0; st<4; ++st)
                dp[st][i/2] = -1;
        }
        cout << solve(0, 0) << endl;
    }
    return 0;
}
