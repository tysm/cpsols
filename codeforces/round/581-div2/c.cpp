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

int32_t main(){
    desync();
    int adj[101][101] = {};
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i){
        string s;
        cin >> s;
        for(int j=0; j<s.size(); ++j){
            if(s[j] == '1')
                adj[i][j+1] = true;
            else
                adj[i][j+1] = INF;
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            for(int k=1; k<=n; ++k)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        }
    }
    int m;
    cin >> m;
    vi grf(m);
    for(int i=0; i<m; ++i)
        cin >> grf[i];

    vi ans;
    for(int i=0; i<m; ++i){
        int x = grf[i];
        ans.pb(x);
        int aux = i;
        for(int j=i+1; j<m-1; ++j){
            int y = grf[j], z = grf[j+1];
            int xz = j+1 - i;
            if(adj[x][z] < xz or (x == z and adj[x][z] != INF)){
                break;
            }
            aux = j;
        }
        i = aux;
    }

    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); ++i){
        if(i)
            cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
