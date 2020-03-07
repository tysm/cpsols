#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double

using ii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vb = vector<bool>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vvd = vector<vd>;
using vvb = vector<vb>;
using vvii = vector<vii>;

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

int32_t main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    vi ans;
    set<char> st;
    map<char, int> clr;
    for(int i=0; i<n; ++i){
        char c = s[i];
        auto it = st.upper_bound(c);
        if(it == st.begin())
            clr[c] = st.size() + 1;
        else{
            it--;
            clr[c] = clr[*it];
            st.erase(it);
        }
        st.insert(c);
        ans.pb(clr[c]);
    }
    cout << st.size() << endl;
    for(int i:ans)
        cout << i << ' ';
    cout << endl;
    return 0;
}
