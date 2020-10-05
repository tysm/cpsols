#include <cpplib/stdinc.hpp>

int n, one, arr[(int)1e2+3], dp[(int)1e2+3][(int)1e2+3][(int)1e2+3];

bool solve(int l, int r, int k){
    if(l == r)
        return true;

    int &res = dp[l][r][k];
    if(res != -1)
        return res;

    res = false;

    for(int i=l; i<one; ++i){
        if(arr[i-1] < arr[i] and arr[i+1] < arr[i]){
            int aux = arr[i];
            arr[i] = -1;
            if(!solve(i+1, r, k+(i-l)))
                res = true;
            arr[i] = aux;
        }
    }

    for(int i=r; i>one; --i){
        if(arr[i-1] < arr[i] and arr[i+1] < arr[i]){
            int aux = arr[i];
            arr[i] = -1;
            if(!solve(l, i-1, k+(r-i)))
                res = true;
            arr[i] = aux;
        }
    }

    if(k and !solve(l, r, k-1))
        res = true;

    return res;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; ++i){
            cin >> arr[i];
            if(arr[i] == 1)
                one = i;
        }
        arr[0] = arr[n+1] = -1;

        memset(dp, -1, sizeof(dp));
        cout << (solve(1, n, 0)? "Alice" : "Bob") << endl;
    }
    return 0;
}
