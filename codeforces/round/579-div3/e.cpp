#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define ff first
#define ss second
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vi v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    int c = 0, ans = 0;
    for(int x:v){
        if(x == c or x == c+1){
            c++;
            ans++;
        }
        else if(x-1 > c){
            c = x-1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
