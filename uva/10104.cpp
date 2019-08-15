#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

using u64 = uint64_t;
using u128 = __uint128_t;

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

inline int mod(int n, int m){
    int ret = n%m; 
    if(ret < 0) ret += m;
    return ret;
}

/**
 * Euclidian GCD.
 *
 * Time Complexity: O(log(min(a, b))).
 */
int gcd(int a, int b, int &x, int &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1, res;
    res = gcd(b%a, a, x1, y1);
    x = y1 - b/a*x1;
    y = x1;
    return res;
}

int32_t main(){
    desync();
    int a, b, x, y, d;
    while(cin >> a >> b){
        d = gcd(a, b, x, y);
        if(a == b){
            int aux = x;
            x = min(x, y);
            y = max(aux, y);
        }
        cout << x << ' ' << y << ' ' << d << endl;
    }
    return 0;
}
