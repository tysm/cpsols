#include <cpplib/stdinc.hpp>
#include <cpplib/adt/ost.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    ost_set<ii> cur;
    set<ii> aux;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;

        cur.insert(ii(i, x));
        aux.ep(x, -i);
    }

    int q;
    cin >> q;
    vector<tuple<int, int, int> > arr;
    for(int i=0; i<q; ++i){
        int k, j;
        cin >> k >> j;
        j--;
        arr.eb(k, j, i);
    }
    sort(rall(arr));

    vi ans(q);
    for(auto [k, j, i] : arr){
        while(cur.size() > k){
            ii x = *aux.begin();
            aux.erase(aux.begin());
            cur.erase(ii(-x.ss, x.ff));
        }
        ans[i] = (*cur.find_by_order(j)).ss;
    }

    for(int i=0; i<q; ++i)
        cout << ans[i] << endl;
    return 0;
}
