#include <cpplib/stdinc.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1645
    desync();
    int n;
    cin >> n;

    stack<ii> seen;
    for(int i=1; i<=n; ++i){
        int x;
        cin >> x;

        while(!seen.empty() and seen.top().ff >= x)
            seen.pop();

        if(i > 1)
            cout << ' ';
        cout << (seen.empty()? 0 : seen.top().ss);

        seen.push({x, i});
    }
    cout << endl;
    return 0;
}
