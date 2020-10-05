#include <cpplib/stdinc.hpp>
#include <cpplib/adt/heap.hpp>

// sum(1...n)/d <= x
// sum(1...n) <= x*d
// sumx(1...n) <= 0

bool solve(vvii &iadj, double x, vi &res){
    int n = iadj.size();
    vd sum(n, LINF);
    vi par(n, -1);
    sum[1] = 0;
    par[1] = 0;
    for(int v=2; v<n; ++v){
        for(auto [u, w] : iadj[v]){
            if(sum[u] + (w-x) <= sum[v]-EPS){
                par[v] = u;
                sum[v] = sum[u] + (w-x);
            }
        }
    }

    bool ok = (sum[n-1] < EPS);
    if(ok){
        res.clear();
        int v = n-1;
        while(par[v]){
            res.eb(v);
            v = par[v];
        }
        res.eb(v);
        reverse(all(res));
    }
    return ok;
}

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vvii iadj(n+1);
    for(int i=0; i<m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        iadj[v].eb(u, w);
    }

    vi res;
    double lo = 0, hi = 100;
    while(lo < hi+EPS){
        double mid = (lo+hi)/2;
        if(solve(iadj, mid, res))
            hi = mid-EPS;
        else
            lo = mid+EPS;

    }

    cout << res.size()-1 << endl;
    cout << res << endl;
    return 0;
}
