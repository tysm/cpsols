#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/modular.hpp>
#include <cpplib/math/combinatorics/modular.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    if(n == 0){
        cout << 1 << endl;
        return 0;
    }
    ModC<> mc(2*n);
    mint ans = 1;
    stack<int> s;
    int cur = -1;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        unordered_map<int, int> cnt;
        while(!s.empty() and x < s.top()){
            cnt[s.top()]++;
            s.pop();
        }
        for(auto p:cnt)
            ans *= mc.catalan(p.ss);
        s.emplace(x);
    }
    unordered_map<int, int> cnt;
    while(!s.empty()){
        cnt[s.top()]++;
        s.pop();
    }
    for(auto p:cnt)
        ans *= mc.catalan(p.ss);
    cout << ans << endl;
    return 0;
}
