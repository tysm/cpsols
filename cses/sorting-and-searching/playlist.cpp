#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1141
    desync();
    int n;
    cin >> n;

    vi v(n);
    for(int &i:v)
        cin >> i;

    int ans = 0;
    map<int, bool> rep;
    for(int i=0, j=0; j<n; ++j){
        while(rep[v[j]])
            rep[v[i++]] = false;
        rep[v[j]] = true;
        ans = max(ans, j-i+1);
    }
    cout << ans << endl;
    return 0;
}
