#include <cpplib/stdinc.hpp>

int solve(int n, int k){
    int ops = 1;
    k--;

    int sz = 1;
    while(ops < n and k >= 4*sz-1){
        k -= 4*sz-1;
        sz *= 2;
        ops++;
    }
    return n - ops;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(n == 2 and k == 3){
            cout << "NO" << endl;
            continue;
        }

        if(n <= 30){
            int op = 1, nl = n, kl = k;
            while(nl--){
                kl -= op;
                op *= 4;
            }
            if(kl > 0)
                cout << "NO" << endl;
            else
                cout << "YES " << solve(n, k) << endl;
        }
        else
            cout << "YES " << solve(n, k) << endl;
    }
    return 0;
}
