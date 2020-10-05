#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vvi arr(n, vi(m));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j)
                cin >> arr[i][j];
        }

        int ans = 0;
        for(int i=0; i<=(n-1)/2; ++i){
            for(int j=0; j<=(m-1)/2; ++j){
                vi aux;
                aux.eb(arr[i][j]);
                arr[i][j] = -1;

                if(arr[n-i-1][j] != -1){
                    aux.eb(arr[n-i-1][j]);
                    arr[n-i-1][j] = -1;
                }
                if(arr[i][m-j-1] != -1){
                    aux.eb(arr[i][m-j-1]);
                    arr[i][m-j-1] = -1;
                }
                if(arr[n-i-1][m-j-1] != -1){
                    aux.eb(arr[n-i-1][m-j-1]);
                    arr[n-i-1][m-j-1] = -1;
                }
                sort(all(aux));

                int lo = aux[0], hi = aux.back();
                while(hi - lo > 2){
                    int m1 = lo + (hi-lo)/3, m2 = hi - (hi-lo)/3;

                    int a1 = 0, a2 = 0;
                    for(int k:aux){
                        a1 += abs(k-m1);
                        a2 += abs(k-m2);
                    }
                    if(a1 < a2)
                        hi = m2-1;
                    else
                        lo = m1+1;
                }
                int res = LINF;
                for(int a = lo; a<=hi; ++a){
                    int acc = 0;
                    for(int k:aux)
                        acc += abs(k-a);
                    res = min(res, acc);
                }
                ans += res;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
