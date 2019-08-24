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
 * Euclidian GCD.
 *
 * Time Complexity: O(log(min(a, b))).
 */
int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

/**
 * Euclidian derivated LCM.
 *
 * Time Complexity: O(log(min(a, b))).
 */
int lcm(int a, int b){
    // same as a*b/gcd(a, b) but avoiding overflow.
    return (a/gcd(a, b))*b;
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

/**
 * Erdos Gallai.
 *
 * Provides a graph realization check,
 * based on its vertices degrees.
 *
 * Time Complexity: O(n).
 * Where n is the size of the graph.
 */
bool erdos(vi dseq){
    // dseq = degree sequence.
    int n = dseq.size();
    sort(dseq.rbegin(), dseq.rend());

    vi psum(dseq);
    for(int i=1; i<n; ++i)
        psum[i] += psum[i-1];

    if(psum[n - 1]%2)
        return false;

    vi minsum(n + 1, 0);
    for(int i=1; i<n; ++i){
        int x = upper_bound(dseq.rbegin(), dseq.rend(), i) - dseq.rbegin();
        // the quantity of degrees less or equal i.

        minsum[i] = i*max(i & 0, n - x - i) + psum[n - 1];
        // using (i & 0) to avoid the use of 0LL when using long long.

        int low = max(i-1, n-x-1);
        if(low >= 0)
            minsum[i] -= psum[low];
    }

    for(int k=1; k<=n; ++k){
        if(psum[k-1] > k*(k - 1) + minsum[k])
            return false;
    }
    return true;
}

int32_t main(){
    desync();
    int n;
    while(cin >> n){
        vi seq(n);
        for(int &x:seq)
            cin >> x;
        cout << (erdos(seq)? "possivel" : "impossivel") << endl;
    }
    return 0;
}
