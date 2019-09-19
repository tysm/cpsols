#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define MAX (int32_t(1e6)+1)
#define INF (int32_t(1e9)+1)
using namespace std;


int32_t main(){
    int v, n;
    cin >> v >> n;
    v*=n;
    for(int i=1; i<=9; ++i){
        if(i-1)
            cout << ' ';
        int x = v*i;
        cout << (int)ceil((long double)x/10);
    }
    cout << endl;
    return 0;
}
