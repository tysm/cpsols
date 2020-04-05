#include <cpplib/stdinc.hpp>
#include <cpplib/data-structures/rolling-hash.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1732
    desync();
    string s;
    cin >> s;

    RollingHash hash(31);
    // Hash h(s);
    for(char c:s)
        hash.push_back(c-'a'+1);

    vi ans;
    for(int i=0; i<s.size()-1; ++i){
        auto qp = hash.query(0, i), qs = hash.query(s.size()-1-i, s.size()-1);
        if(qp == qs)
            ans.pb(i+1);
    }
    for(int i=0; i<ans.size(); ++i){
        if(i)
            cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
