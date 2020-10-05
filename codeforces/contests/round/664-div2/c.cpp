#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    vi A(n), B(m);
    for(int &i:A)
        cin >> i;
    for(int &i:B)
        cin >> i;
    int ans = -1;
    for(int k=0; k<(1<<9) and ans == -1; ++k){
        bool ok = true;
        for(int i=0; i<n and ok; ++i){
            bool fine = false;
            for(int j=0; j<m and !fine; ++j){
                int c = A[i] & B[j];
                if((c & k) == c)
                    fine = true;
            }
            if(!fine)
                ok = false;
        }
        if(ok)
            ans = k;
    }
    cout << ans << endl;
    return 0;
}
