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
    int n, m;
    cin >> n;
    map<int, bool> belongs;

    int arr[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        belongs[arr[i]] = true;
    }
    cin >> m;
    int brr[m];
    for(int i=0; i<m; ++i){
        cin >> brr[i];
        belongs[brr[i]] = true;
    }
    int a, b, v = 0;
    for(int i=0; i<n and !v; ++i){
        for(int j=0; j<m and !v; ++j){
            if(!belongs[arr[i]+brr[j]]){
                a = arr[i];
                b = brr[j];
                v = 1;
            }
        }
    }
    cout << a << ' ' << b << endl;
    return 0;
}
