#include <bits/stdc++.h>
#define INF int32_t(1e9)+1
#define int long long
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;

int32_t main(){
    int n, a, b, k, ans = 0;
    cin >> n >> a >> b >> k;
    vector<int> v;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;

        int hp = x%(a+b);
        if(hp == 0)
            hp = a+b;

        if(hp <= a)
            ans++;
        else{
            hp-=a;
            v.push_back(hp/a+(hp%a?1:0));
        }
    }
    sort(v.begin(), v.end());
    for(auto i:v){
        if(i<=k){
            ans++;
            k-=i;
        }
    }
    cout << ans << endl;
    return 0;
}
