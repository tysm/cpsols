#include <cpplib/stdinc.hpp>

vi link(2e5), when(2e5, INF), val(2e5);
vvii block(2e5);

int get(int u, int t = -1){
    if(u == link[u])
        return u;
    return t < when[u]? get(link[u], t) : u;
}

void merge(int u, int v, int t){
    u = get(u);
    v = get(v);
    if(u == v)
        return;
    if(block[u].size() < block[v].size())
        swap(u, v);
    link[v] = u;
    when[v] = t;
    for(auto &[x, y]:block[v])
        block[u].eb(x, t);
}

int solve(int u, int t){
    u = get(u, t);
    while(!block[u].empty()){
        auto [x, y] = block[u].back();
        if(y > t and val[x] != 0)
            return x;
        block[u].pop_back();
    }
    return -1;
}

int32_t main(){
    desync();
    iota(all(link), 0);

    int n, m, q;
    cin >> n >> m >> q;

    for(int i=0; i<n; ++i)
        cin >> val[i];

    vii edgs(m);
    for(auto &[u, v]:edgs){
        cin >> u >> v;
        u--;
        v--;
    }

    vb del(m);
    vii query(q);
    for(auto &[op, x]:query){
        cin >> op >> x;
        x--;
        if(op == 2)
            del[x] = true;
    }

    for(int i=0; i<n; ++i){
        when[i] = q;
        block[i].eb(i, q);
    }

    for(int i=0; i<m; ++i){
        if(del[i])
            continue;
        auto [u, v] = edgs[i];
        merge(u, v, q);
    }

    for(int t=q-1; t>=0; --t){
        auto [op, x] = query[t];
        if(op == 1)
            continue;
        auto [u, v] = edgs[x];
        merge(u, v, t);
    }

    for(int k=0; k<n; ++k)
        sort(all(block[k]), [&](pair<int, int> &i, pair<int, int> &j){ return val[i.ff] < val[j.ff]; });

    for(int t=0; t<q; ++t){
        auto [op, x] = query[t];
        if(op == 2)
            continue;
        int ans = solve(x, t);
        cout << (ans == -1? 0 : val[ans]) << endl;
        if(ans != -1)
            val[ans] = 0;
    }
    return 0;
}
