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
 * Linear Diophantine Equation Solution.
 *
 * Returns the roots of the given LDE.
 *
 * Note: it doesn't check if "a*x + b*y = c"
 * is a LDE, i.e. if gcd(abs(a), abs(b)) divides c.
 *
 * Time Complexity: O(log(min(a, b))).
 */
ii lde(int a, int b, int c){
    pair<int, ii> _gcd = gcd(abs(a), abs(b));

    int x = _gcd.ss.ff, y = _gcd.ss.ss, g = _gcd.ff;
    x *= c/g;
    y *= c/g;

    if(a < 0)
        x = -x;
    if(b < 0)
        y = -y;
    return {x, y};
}

int32_t main(){
    desync();
    int a, b, c;
    cin >> a >> b >> c;
    auto _g = gcd(a, b);
    bool valid = !(c%_g.ff);
    if(valid){
        auto roots = lde(a, b, c);
        double lhs = -roots.ff, rhs = roots.ss;
        lhs *= _g.ff;
        lhs /= b;
        rhs *= _g.ff;
        rhs /= a;
        lhs = ceil(lhs);
        rhs = floor(rhs);
        if(rhs - lhs < 0)
            valid = false;
    }
    cout << (valid? "Yes" : "No") << endl;
    return 0;
}
