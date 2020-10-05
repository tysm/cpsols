#include <cpplib/stdinc.hpp>

void solve(int n, int up, vi &cur){
    if(!n){
        for(int i=0; i<cur.size(); ++i)
            cout << cur[i] << "+\n"[i == cur.size()-1];
        return;
    }
    for(int i=up; i>=1; --i){
        if(n - i < 0)
            continue;
        cur.eb(i);
        solve(n-i, i, cur);
        cur.pop_back();
    }
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi cur;
    solve(n, n, cur);
    return 0;
}
