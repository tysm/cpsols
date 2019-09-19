#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pb push_back
#define INF (int32_t(1e9)+1)
using namespace std;

vi v;

bool solve(int m, int c){
    int i = 0, cur = 0;
    while(c > 0 and i < v.size()){
        if(cur + v[i] <= m){
            cur += v[i];
            i++;
        }
        else{
            c--;
            cur = 0;
        }
    }
    return i == v.size();
}

int32_t main(){
    int n, c, t;
    cin >> n >> c >> t;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        v.pb(x);
    }
    int low = 0, high = INF, ans = INF;
    while(low <= high){
        int m = (low+high)/2;
        if(solve(m*t, c)){
            high = m-1;
            ans = min(ans, m);
        }
        else
            low = m+1;
    }
    cout << ans << endl;
    return 0;
}
