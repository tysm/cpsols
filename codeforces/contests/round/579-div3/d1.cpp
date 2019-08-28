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
    int ans = 0;
    for(int i=0; i<s.size(); ++i){
        for(int j=i; j<s.size(); ++j){
            int pos = 0;
            for(int k=0; k<s.size(); ++k){
                if(k>=i and k<=j)
                    continue;
                if(s[k] == t[pos])
                    pos++;
                if(pos == t.size())
                    break;
            }
            if(pos == t.size())
                ans = max(ans, abs(j-i)+1);
        }
    }
    cout << ans << endl;
    return 0;
}
