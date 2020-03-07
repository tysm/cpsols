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

    char l0 = 0, l1 = 0;
    for(int i=0; i<n; ++i){
        char c = s[i];
        if(c >= l0){
            l0 = c;
            s[i] = '0';
        }
        else if(c >= l1){
            l1 = c;
            s[i] = '1';
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl << s << endl;
}
