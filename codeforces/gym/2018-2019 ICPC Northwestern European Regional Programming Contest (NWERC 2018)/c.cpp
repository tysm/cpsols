#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geometry/point.hpp>

int n;
vvi adj;
vi cnt;
vector<point<double> > ans;

void precompute(int u, int p = -1){
    cnt[u] = 1;
    for(int v:adj[u]){
        if(v == p)
            continue;
        precompute(v, u);
        cnt[u] += cnt[v];
    }
}

void dfs(double l, double r, int u, int p = -1){
    cnt[u]--;
    double rng = r - l;
    for(int v:adj[u]){
        if(v == p)
            continue;
        double reg = ((double)cnt[v]/cnt[u])*rng;
        ans[v] = ans[u] + rotate(point<double>(1, 0), point<double>(0, 0, 1), (l + reg/2)*acos(-1)/180);
        dfs(l, l+reg, v, u);
        l += reg+EPS;
    }
}

int32_t main(){
    desync();
    cin >> n;
    adj.resize(n+1);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].eb(b);
        adj[b].eb(a);
    }
    cnt.resize(n+1);
    precompute(1);
    ans.resize(n+1);
    dfs(0, 360.0-EPS, 1);
    cout.precision(10);
    for(int i=1; i<=n; ++i)
        cout << ans[i].x << ' ' << ans[i].y << endl;
    return 0;
}
