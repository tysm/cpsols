#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

using ii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vb = vector<bool>;
using vii = vector<ii>;
using vvi = vector<vi>;

#define ff first
#define ss second
#define pb push_back

#define EPS 1e-9
#define INF (int32_t(1e9)+1)
#define MAX (int32_t(1e6)+1)
#define M (int32_t(1e9)+7)

#define endl "\n"
#define debug(x) (cerr << #x << " = " << (x) << endl)
#define desync() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))


int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, c, ans = -INF;
        cin >> c >> n;

        vvi w(n);
        for(int i=0; i<n; ++i){
            int k;
            cin >> k;
            for(int j=0; j<k; ++j){
                int x;
                cin >> x;
                w[i].pb(x);
            }
        }

        vb dp(c+1, false), aux;
        dp[0] = true;
        for(int i=0; i<n; ++i){
            aux = vb(c+1, false);
            for(auto j:w[i]){
                for(int k=0; k<=c; ++k){
                    if(dp[k] and k+j <= c)
                        aux[k+j] = true;
                }
            }
            swap(dp, aux);
        }
        for(int i=1; i<=c; ++i){
            if(dp[i])
                ans = i;
        }
        if(ans == -INF)
            cout << "no solution" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
