#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;
    vi r(n+1), c(n+1);
    for(int i=1; i<=n; ++i){
        cin >> r[i];
        r[i] = r[i]%2 + r[i-1];
    }
    for(int i=1; i<=n; ++i){
        cin >> c[i];
        c[i] = c[i]%2 + c[i-1];
    }
    while(q--){
        int ra, ca, rb, cb;
        cin >> ra >> ca >> rb >> cb;
        if(ra > rb)
            swap(ra, rb);
        if(ca > cb)
            swap(ca, cb);
        int i = r[rb] - r[ra-1], j = c[cb] - c[ca-1];
        if(!i and !j or i == rb-ra+1 and j == cb-ca+1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
