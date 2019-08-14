#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

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
    return gcd(b%a, b);
}

/// Binary Exponentiation.
int bexp(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

/// Binary Exponatiation with module.
int bexpm(int a, int b, int m = M){
    a %= m;
    int res = 1;
    while(b > 0){
        if(b & 1)
            res = (res*a)%m;
        a = (a*a)%m;
        b >>= 1;
    }
    return res;
}

int32_t main(){
    int n;
    cin >> n;
    int res = 2*4*3*bexp(4, n-3);
    if(n > 3)
        res += (n-3)*4*3*3*bexp(4, n-4);
    cout << res << endl;
    return 0;
}
