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
 * Extended Euclidian GCD.
 *
 * Time Complexity: O(log(min(a, b))).
 */
pair<int, ii> gcd(int a, int b){
    if(a == 0) return {b, {0, 1}};
    pair<int, ii> res = gcd(b%a, a);
    int x1 = res.ss.ff, y1 = res.ss.ss;
    return {res.ff, {y1 - b/a*x1, x1}};
}
 
/**
 * Euclidian derivated LCM.
 *
 * Time Complexity: O(log(min(a, b))).
 */
int lcm(int a, int b){
    // same as a*b/gcd(a, b) but avoiding overflow.
    return a/gcd(a, b).ff*b;
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
    int n;
    cin >> n;
    int ones = 0;
    string s;
    cin >> s;
    for(int i=0; i<n; ++i){
        if(s[i] == 'n')
            ones++;
    }
    for(int i=0; i<ones; ++i){
        if(i)
            cout << ' ';
        cout << 1;
    }
    for(int i=0; i<(n-(ones*3))/4; ++i){
        if(i or ones)
            cout << ' ';
        cout << 0;
    }
    cout << endl;
    return 0;
}
