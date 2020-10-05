#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, k, m, q;
    cin >> n >> k >> m >> q;

    int l = k-1, r = n-k;
    while(q--){
        int op, i;
        cin >> op >> i;
        if(op){
            if(i <= k){
                l++;
                k++;
            }
            else
                r++;
            n++;
        }
        else{
            if(i >= k)
                r = i-k;
            else{
                int d = l - (k-i-1);
                l = k-i-1;
                k -= d;
            }
            n = l+r+1;
        }
        cout << n << ' ' << k << endl;
    }
    return 0;
}
