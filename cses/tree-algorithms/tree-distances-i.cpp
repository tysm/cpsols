#include <cpplib/stdinc.hpp>

void dfs1(vvi &adj, vector<pair<ii, ii> > &aux, int p, int u){
    // debug(p);
    // debug(u);
    pair<ii, ii> res;
    for(int v:adj[u]){
        if(v == p)
            continue;
        dfs1(adj, aux, u, v);

        if(aux[v].ff.ff+1 > res.ff.ff){
            swap(res.ff, res.ss);
            res.ff = {aux[v].ff.ff+1, v};
        }
        else if(aux[v].ff.ff+1 > res.ss.ff)
            res.ss = {aux[v].ff.ff+1, v};
    }
    // debug(u);
    // debug(res.ff.ff);
    // debug(res.ff.ss);
    // debug(res.ss.ff);
    // debug(res.ss.ss);
    aux[u] = res;
}

void dfs2(vvi &adj, vector<pair<ii, ii> > &aux, vi &dis, int acc, int p, int u){
    dis[u] = max(acc, aux[u].ff.ff);
    // debug(p);
    // debug(u);
    // debug(acc);
    // debug(res.ff.ff);
    // debug(res.ff.ss);
    // debug(res.ss.ff);
    // debug(res.ss.ss);
    // debug(dis[u]);
    for(int v:adj[u]){
        if(v == p)
            continue;
        int vacc = acc+1;
        if(v == aux[u].ff.ss)
            vacc = max(vacc, aux[u].ss.ff+1);
        else
            vacc = max(vacc, aux[u].ff.ff+1);
        dfs2(adj, aux, dis, vacc, u, v);
    }
}

int32_t main(){
    // https://cses.fi/problemset/task/1132
    desync();
    int n;
    cin >> n;

    if(n <= 2){
        for(int i=1; i<=n; ++i){
            if(i > 1)
                cout << ' ';
            cout << n-1;
        }
        cout << endl;
        return 0;
    }

    vvi adj(n+1);
    for(int i=1; i<n; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi dis(n+1);
    vector<pair<ii, ii> > aux(n+1);
    for(int i=1; i<=n; ++i){
        if(adj[i].size() >= 2){
            // debug(i);
            dfs1(adj, aux, -1, i);
            dfs2(adj, aux, dis, 0, -1, i);
            break;
        }
    }
    for(int i=1; i<=n; ++i){
        if(i > 1)
            cout << ' ';
        cout << dis[i];
    }
    cout << endl;
    return 0;
}
