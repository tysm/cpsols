#include <bits/stdc++.h>
#define int long long
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

#define ff first
#define ss second
#define pb push_back

#define EPS 1e-9
#define INF (int32_t(1e9)+1)
#define MAX (int32_t(1e6)+1)
#define M (int32_t(1e9)+7)

#define endl "\n"
#define debug(x) (cerr << #x << " = " << (x) << endl)
#define desync() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))


int32_t main(){
    desync();
    int n;
    cin >> n;
    int ans = 0, neg = 0, zer = 0;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        if(x < 0){
            ans += abs(x + 1);
            neg++;
        }
        else if( x > 0)
            ans += x - 1;
        else
            zer++;
    }
    if(neg%2){
        if(zer){
            ans++;
            zer--;
        }
        else
            ans+=2;
    }
    ans += zer;
    cout << ans << endl;
    return 0;
}
