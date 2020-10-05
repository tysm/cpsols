#include <cpplib/stdinc.hpp>

bool check(int n, int m, vector<list<int> > iadj, vvb mat, vi dg, int k){
    queue<ii> q;
    set<int> inq;

    for(int u=0; u<n; ++u){
        for(int v=0; v<n; ++v){

        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        inq.erase(u);

        for(auto it=iadj[u].begin(); it != iadj[u].end();){
            int v = *it;
            if(dg[u] + dg[v] < k){
                it++;
                continue;
            }
            m++;
            dg[u]++;
            dg[v]++;
            if(!inq.count(u)){
                inq.ep(u);
                q.ep(u);
            }
            if(!inq.count(v)){
                inq.ep(v);
                q.ep(v);
            }
            it = iadj[u].erase(it);
        }
    }
    return m == n*(n-1)/2;
}

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vi dg(n);
    vvb mat(n, vb(n));
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        dg[u]++;
        dg[v]++;

        mat[u][v] = mat[v][u] = true;
    }
    vector<list<int> > iadj(n);
    for(int u=0; u<n; ++u){
        for(int v=u+1; v<n; ++v){
            if(mat[u][v])
                continue;
            iadj[u].eb(v);
        }
    }

    int lo = 0, hi = 2*n, ans = hi;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        if(check(n, m, iadj, mat, dg, mid)){
            ans = mid;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    cout << ans << endl;
    return 0;
}
