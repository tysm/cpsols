#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define ms(v,x) memset(v,x,sizeof(v))
#define ff first
#define ss second
#define td(v) v.begin(),v.end()
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define re(v) {for(auto &_re : v) cin >> _re;}
#define rre(v){for(auto &_re : v) for(auto &_rre : _re) cin >> _rre;}
#define pr(v) {for(auto _pr : v) cout << _pr << " "; cout << endl;}
#define prr(v) {for(auto _prr : v) cout << _prr.ff << " " << _prr.ss << endl;}
#define eb emplace_back
using namespace std;
const ll M = 1e9 + 7;
const ll mod = 998244353;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define int long long
struct range{
	ll l,r,val;
	void read(){
		cin >> l >> r >> val;
	}
	bool operator<(const range &nxt) const {
		return l < nxt.l;
	}
};
void solve(){
	ll m,k;
	cin >> m >> k;
	vector<range> v(m);
	for(range &r : v) r.read();
	sort(td(v));
	vector<ll> pf(m), l_bound(m), r_bound(m);
	pf[0] = v[0].val * (v[0].r - v[0].l + 1);
	l_bound[0] = v[0].l;
    r_bound[0] = v[0].r;
	for(int i=1;i<m;i++){
		pf[i] = pf[i-1] + (v[i].val) * (v[i].r - v[i].l + 1);
		l_bound[i] = v[i].l;
        r_bound[i] = v[i].r;
	}
	auto sum = [&](int l,int r){
		if(l == 0) return pf[r];
		else return pf[r] - pf[l-1];
	};
	ll ans = 0;
	for(int i=0;i<m;i++){
		int p = lower_bound(td(l_bound), v[i].l + k) - l_bound.begin();
		p--;
		if(i==p){
			ans = max(ans, min(v[i].r - v[i].l + 1, k) * v[i].val);
			continue;
		}
		if(v[p].l >= v[i].l + k){
			ans = max(ans, sum(i, p-1));
		}
		else{
			ans = max(ans, sum(i, p-1) + min(v[p].r - v[p].l + 1, k - (v[p].l-v[i].l)) * v[p].val);
		}
	}
    for(int i=0; i<m; ++i){
        int lpos = v[i].r - (k-1);
        int p = lower_bound(td(r_bound), lpos) - r_bound.begin();
        if(i == p){
            ans = max(ans, min(v[i].r - v[i].l + 1, k) * v[i].val);
            continue;
        }

        if(v[p].l > lpos)
            ans = max(ans, sum(p, i));
        else
            ans = max(ans, (v[p].r - lpos + 1)*v[p].val + sum(p+1, i));
    }
	cout << ans << endl;
}
int32_t main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }  
}
