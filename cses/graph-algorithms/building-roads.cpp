#include <cpplib/stdinc.hpp>
#include <cpplib/data-structures/union-find.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1666
    desync();
    int n, m;
    cin >> n >> m;
    UnionFind dsu(n+1);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        dsu.merge(a, b);
    }
    set<int> roots;
    for(int i=1; i<=n; ++i)
        roots.insert(dsu.find(i));
    cout << roots.size()-1 << endl;
    if(roots.size() > 1){
        auto it = roots.begin();
        int last = *it;
        it++;
        while(it != roots.end()){
            cout << last << ' ' << *it << endl;
            last = *it;
            it++;
        }
    }
    return 0;
}
