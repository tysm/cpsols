#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vb row(n), col(m);
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                int x;
                cin >> x;
                if(x)
                    row[i] = col[j] = true;
            }
        }
        int ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(!row[i] and !col[j]){
                    ans++;
                    row[i] = col[j] = true;
                }
            }
        }
        ans %= 2;
        if(ans)
            cout << "Ashish" << endl;
        else
            cout << "Vivek" << endl;
    }
    return 0;
}
