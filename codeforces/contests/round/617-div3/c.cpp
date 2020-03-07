#include <bits/stdc++.h>
#define INF int32_t(1e9)+1
#define int long long
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int ans = INF, l, r;
        map<ii, int> m;

        ii pos = {0, 0};
        m[pos] = 0;

//        cout << "POSi: " << -1 << ' ' << pos.ff << ' ' << pos.ss << endl;

        for(int i=0; i<n; ++i){
            switch(s[i]){
                case 'L':
                    pos.ff--;
                    break;
                case 'R':
                    pos.ff++;
                    break;
                case 'D':
                    pos.ss--;
                    break;
                case 'U':
                    pos.ss++;
                    break;
                default:
                    break;
            }
            if(m.count(pos) and (i+1)-(m[pos]+1) < ans){
                ans = (i+1)-(m[pos]+1);
                l = m[pos]+1;
                r = i+1;
            }
            m[pos] = i+1;
        }
        if(ans == INF)
            cout << -1 << endl;
        else
            cout << l << ' ' << r << endl;
    }
    return 0;
}
