#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define ii pair<int, int>
#define OK (cerr << "OK" << endl)
#define debug(x) cerr << #x " = " << (x) << endl
#define ff first
#define ss second
#define int long long
#define tt tuple<int, int, int>
#define all(x) x.begin(), x.end()
#define Matrix vector<vector<int>>
#define Mat(n, m, v) vector<vector<int>>(n, vector<int>(m, v))
#define endl '\n'

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string str(const int n, const int c) {
  string ans;
  for (int i = 0; i < n; ++i)
    ans += char(rng() % c + 'a');
  return ans;
}

string str01(const int n) {
  string ans;
  for (int i = 0; i < n; ++i) {
    if (rng() % 2)
      ans += '?';
    else
      ans += char(rng() % 2 + '0');
  }
  return ans;
}

int num(const int n) { return rng() % n + 1; }

int num(const int l, const int r) {
  int sz = r - l + 1;
  int n = rng() % sz;
  return n + l;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cout << t << endl;
  while (t--) {
    // const int MAXN = 6;
    int n = num(1, 20);
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
      cout << num(1, 10) << ' ' << num(1, 10) << endl;
    }
  }
}
