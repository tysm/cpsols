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
#define INF int32_t(1e9)+1
#define MAX int32_t(1e6)+1
#define M int32_t(1e9)+7

#define endl "\n"
#define debug(x) (cerr << #x << " = " << (x) << endl)
#define desync() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

inline int mod(int n, int m){
    int ret = n%m; 
    if(ret < 0) ret += m;
    return ret;
}

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

/**
 * Binary Exponentiation.
 *
 * Time Complexity: O(log(e)).
 */
int bexp(int b, int e){
    int res = 1;
    while(e > 0){
        if(e & 1)
            res *= b;
        b *= b;
        e >>= 1;
    }
    return res;
}

/**
 * Binary Exponentiation with mod.
 *
 * Time Complexity: O(log(e)).
 */
int bexpm(int b, int e, int m = M){
    b %= m;
    int res = 1;
    while(e > 0){
        if(e & 1)
            res = (res*b)%m;
        b = (b*b)%m;
        e >>= 1;
    }
    return res;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n<=1){
            cout << n << endl;
            continue;
        }
        int e;
        if(n%3 != 1)
            e = n/3;
        else
            e = max(0LL, n/3 - 1);
        int res = bexpm(3, e);
        if(n%3 == 2)
            res = res*2%(M);
        else if(n%3 == 1)
            res = res*4%(M);
        cout << res << endl;
    }
    return 0;
}
