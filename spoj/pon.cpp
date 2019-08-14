#define INT_LL
#ifdef double
#   define DOUBLE_LD
#   undef double
#endif
#include <bits/stdc++.h>
#ifdef INT_LL
#   define int long long
#endif
#ifdef DOUBLE_LD
#   define double long double
#endif
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

int gcd(int a, int n){
    if(a == 0) return n;
    return gcd(n%a, a);
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
u64 ubexpm(u64 b, u64 e, u64 m){
    b %= m;
    u64 res = 1;
    while(e){
        if(e & 1)
            res = ((u128)res*b)%m;
        b = ((u128)b*b)%m;
        e >>= 1;
    }
    return res;
}

/**
 * Miller-Rabin Deterministic Test.
 *
 * Returns true when n is prime,
 * false otherwise.
 *
 * Time Complexity: O(log(n)).
 */
bool isprimel(u64 n){
    if(n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while((d & 1) == 0){
        r++;
        d >>= 1;
    }

    for(int i:{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if(n == i)
            return true;

        u64 x = ubexpm(i, d, n);
        if(x == 1 or x == n - 1)
            continue;

        bool check = true;
        for(int j=1; j<r and check; ++j){
            x = ((u128)x*x)%n;
            if(x == n - 1)
                check = false;
        }
        if(check)
            return false;
    }
    return true;
}

int32_t main(){
    desync();
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(isprimel(x))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}
