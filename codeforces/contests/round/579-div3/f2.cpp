#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define ff first
#define ss second
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, r;
    cin >> n >> r;
    vii pos, neg;
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        if(b < 0)
            neg.pb({max(a, -b), b});
        else
            pos.pb({a, b});
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), [](ii i, ii j){ return i.ff+i.ss > j.ff+j.ss; });

    int taken = 0;
    for(ii &i:pos){
        if(i.ff <= r){
            r += i.ss;
            taken++;
        }
    }

    vector<vi> dp(neg.size()+1, vi(r+1, 0));
    dp[0][r] = taken;
    for(int i=0; i< neg.size(); ++i){
        for(int j=0; j<=r; ++j){
            if(j >= neg[i].ff and j + neg[i].ss >= 0)
                dp[i+1][j+neg[i].ss] = max(dp[i+1][j+neg[i].ss], dp[i][j] + 1);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }

    taken = 0;
    for(int i=0; i<=r; ++i)
        taken = max(taken, dp[neg.size()][i]);

    cout << taken << endl;
    return 0;
}
