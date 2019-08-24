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


int32_t main(){
    int n;
    while(scanf("%lld", &n) == 1){
        vi v(n);
        for(int &x:v)
            scanf("%lld", &x);

        sort(v.rbegin(), v.rend());

        vi psum(v);
        for(int i=1; i<psum.size(); ++i)
            psum[i] += psum[i-1];

        vi mpsum(n);
        for(int k=0; k<n; ++k){
            int i = upper_bound(v.rbegin(), v.rend(), k) - v.rbegin();

            int soma = k*max(0LL, n-i-k);

            soma += psum[n-1];
            int low = max(k-1, n-i-1);
            if(low >= 0)
                soma -= psum[low];

            mpsum[k] = soma;
        }

        bool valid = true;
        if(psum[n-1]%2)
            valid = false;
        for(int k=0; k<n; ++k){
            int lhs = psum[k];
            int rhs = k*(k+1) + (k < n-1? mpsum[k+1] : 0);

            if(lhs > rhs)
                valid = false;
        }

        printf("%s\n", (valid? "possivel" : "impossivel"));
    }
    return 0;
}

