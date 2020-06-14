#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;

    vi rate(n+1), place(n+1);
    vector<multiset<int> > kg(212345);
    for(int i=1; i<=n; ++i){
        cin >> rate[i] >> place[i];
        kg[place[i]].insert(-rate[i]);
    }

    multiset<int> ans;
    for(multiset<int> &m:kg){
        if(!m.empty())
            ans.insert(-(*m.begin()));
    }

    while(q--){
        int x, y;
        cin >> x >> y;
        int r = rate[x], p = place[x];

        ans.erase(ans.lower_bound(-(*kg[p].begin())));
        if(!kg[y].empty())
            ans.erase(ans.lower_bound(-(*kg[y].begin())));

        kg[p].erase(kg[p].lower_bound(-r));
        kg[y].insert(-r);
        place[x] = y;

        if(!kg[p].empty())
            ans.insert(-(*kg[p].begin()));
        ans.insert(-(*kg[y].begin()));

        cout << *ans.begin() << endl;
    }
    return 0;
}
