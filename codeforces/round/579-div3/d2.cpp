#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define ff first
#define ss second
using namespace std;

int32_t main(){
    string s, t;
    cin >> s >> t;

    vi lr(t.size()+1, -1), rl(t.size()+1, s.size());
    int lrp = 0, rlp = t.size() - 1, ans  = 0;
    for(int i=0; i<s.size(); ++i){
        int j = s.size() - 1 - i;
        if(lrp < t.size() and s[i] == t[lrp]){
            lrp++;
            lr[lrp] = i;
        }
        if(rlp >= 0 and s[j] == t[rlp]){
            rl[rlp] = j;
            rlp--;
        }
    }
    for(int i=0; i<=t.size(); ++i)
        ans = max(ans, rl[i] - 1 - lr[i]);
    cout << ans << endl;
    return 0;
}
