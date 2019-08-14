#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define ff first
#define ss second
using namespace std;

int32_t main(){
    int q;
    cin >> q;
    for(int i=0; i<q; ++i){
        int n;
        cin >> n;
        bool clock=true, counterclock=true;
        int curid, lastid;
        for(int j=0; j<n; ++j){
            cin >> curid;
            if(j){
                if(curid != 1 and curid - 1 != lastid)
                    clock = false;
                if(curid != n and curid + 1 != lastid)
                    counterclock = false;
            }
            lastid = curid;
        }
        if(clock or counterclock)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
