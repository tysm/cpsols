#include <cpplib/stdinc.hpp>
#include <cpplib/data-structures/trees/order-statistic-tree.hpp>

int32_t main(){
    // https://cses.fi/problemset/task/1629
    desync();
    int n;
    cin >> n;

    ost_set<ii> s;
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        s.insert({a, b});
    }
    n = s.size();

    vi dp(n);
    int i = n;
    auto it = s.end();
    do{
        i--;
        it--;

        int a = it->ff, b = it->ss;
        if(i < n-1)
            dp[i] = dp[i+1];

        int next = s.order_of_key({b, 0});
        if(next < n)
            dp[i] = max(dp[i], 1 + dp[next]);
        else
            dp[i] = max(dp[i], 1LL);
    }while(it != s.begin());
    cout << dp[0] << endl;
    return 0;
}
