#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/math/modop.hpp>

int n;
vvi adj(300);
vector<point<int> > pl(300);
double dp[300][300][300];

double solve(int l, int r, int idx){
    double &res = dp[idx][l][r];
    if(res > -1)
        return res;
    res = 0;

    for(int v:adj[idx]){
        double dist = distance(pl[idx], pl[v]);
        if(r < l){
            if(v > r and v < l)
                continue;
        }
        else{
            if(v < l or v > r)
                continue;
        }
        res = max(res, dist);
        if(v != r){
            if(idx == r){
                if(v != mod(r-1, n))
                    res = max(res, dist + solve((v+1)%n, mod(r-1, n), v));
            }
            else
                res = max(res, dist + solve((v+1)%n, r, v));
        }
        if(v != l){
            if(idx == l){
                if((l+1)%n != v)
                    res = max(res, dist + solve((l+1)%n, mod(v-1, n), v));
            }
            else
                res = max(res, dist + solve(l, mod(v-1, n), v));
        }
    }
    return res;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        cin >> n;

        for(int i=0; i<n; ++i){
            cin >> pl[i].x >> pl[i].y;
            adj[i].clear();
            for(int j=0; j<n; ++j){
                for(int k=0; k<n; ++k)
                    dp[i][j][k] = -100;
            }
        }

        int m;
        cin >> m;
        for(int i=0; i<m; ++i){
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].eb(b);
            adj[b].eb(a);
        }

        double ans = 0;
        for(int i=0; i<n; ++i)
            ans = max(ans, solve((i+1)%n, mod(i-1, n), i));
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}
