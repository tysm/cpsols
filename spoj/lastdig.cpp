#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M int32_t(1e9)+7
#define endl "\n"
#define desync() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL))

/**
 * Binary Exponentiation with mod.
 *
 * Time Complexity: O(log(e)).
 */
int bexpm(int b, int e, int m = M){
    b %= m;
    int res = 1;
    while(e > 0){
        if(e & 1)
            res = (res*b)%m;
        b = (b*b)%m;
        e >>= 1;
    }
    return res;
}

int32_t main(){
    desync();
    int n;
    cin >> n;
    while(n--){
        int a, e;
        cin >> a >> e;
        cout << bexpm(a, e, 10) << endl;
    }
    return 0;
}
