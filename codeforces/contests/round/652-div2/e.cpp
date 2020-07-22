#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;
    vi w(n), s(n), v[n];
    for(int &i:w)
        cin >> i;

    vi x(m), y(m);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        x[i] = --a;
        y[i] = --b;
        s[a]++;
        s[b]++;
        v[a].eb(i);
        v[b].eb(i);
    }

    min_heap<ii> pq;

    vb vis(n);
    for(int i=0; i<n; ++i){
        if(s[i])
            pq.emplace(max((int)0, s[i]-w[i]), i);
        else
            vis[i] = true;
    }

    vi ans;
    vb ok(m);
    while(!pq.empty()){
        ii p = pq.top();
        pq.pop();
        int acc = p.ff, i = p.ss;

        if(acc != max((int)0, s[i]-w[i]))
            continue;
        if(acc > 0){
            cout << "DEAD" << endl;
            return 0;
        }

        vi wt;
        for(int u:v[i]){
            if(ok[u])
                continue;
            ans.eb(u+1);
            if(x[u] == i)
                swap(x[u], y[u]);
            if(!vis[x[u]])
                wt.eb(x[u]);
            ok[u] = true;
        }

        sort(all(wt));
        for(int j=0; j<wt.size(); ++j){
            s[wt[j]]--;
            if(j == wt.size()-1 or wt[j+1] != wt[j]){
                if(s[wt[j]]){
                    if(max((int)0, s[wt[j]]-w[wt[j]]) == 0)
                        vis[wt[j]] = true;
                    pq.emplace(max((int)0, s[wt[j]]-w[wt[j]]), wt[j]);
                }
            }
        }
    }
    cout << "ALIVE" << endl;
    reverse(all(ans));
    cout << ans << endl;
    return 0;
}
