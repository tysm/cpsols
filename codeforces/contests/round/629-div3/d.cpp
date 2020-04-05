#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vi v(n);
        int segrep = -1;
        for(int i=0; i<n; ++i){
            cin >> v[i];
            if(i and v[i-1] == v[i])
                segrep = i;
        }

        int k = 1, cur = 0;
        vi c(n);
        c[0] = cur;
        for(int i=1; i<n; ++i){
            if(v[i] != v[i-1]){
                cur ^= 1;
                k = 2;
            }
            c[i] = cur;
        }
        if(n>=3 and c[0] == c[n-1] and v[0] != v[n-1]){
            if(segrep != -1){
                cur = (c[segrep-1] ^ 1);
                c[segrep] = cur;
                for(int i=segrep+1; i<n; ++i){
                    if(v[i] != v[i-1])
                        cur ^= 1;
                    c[i] = cur;
                }
            }
            else{
                c[n-1] = 2;
                k = 3;
            }
        }

        cout << k << endl;
        for(int i=0; i<n; ++i){
            if(i)
                cout << ' ';
            cout << c[i] + 1;
        }
        cout << endl;
    }
    return 0;
}
