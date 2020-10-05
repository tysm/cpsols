#include <cpplib/stdinc.hpp>

int func(int a, int b, vi &arr){
    int k = b-a;
    if(a == b)
        return arr[a];
    else if(b == a+1 or b == a+2)
        return arr[a]^arr[b];
    else
        return arr[a]^arr[a+k/3]^arr[b-k/3]^arr[b];
}

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arr(n);
    for(int &i:arr)
        cin >> i;

    vvi ans(n, vi(n, -1));
    for(int k=0; k<n; ++k){
        for(int i=0; i<n-k; ++i){
            int j = i+k;
            int &res = ans[i][j];
            res = func(i, j, arr);
            if(j != i){
                res = max(res, ans[i+1][j]);
                res = max(res, ans[i][j-1]);
            }
        }
    }

    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << ans[a-1][b-1] << endl;
    }
    return 0;
}
