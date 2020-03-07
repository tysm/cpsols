#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool par = true, imp = true;
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            if(x%2)
                par = false;
            else
                imp = false;
        }
        if((!par and !imp) or (imp and n%2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
