#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int cols[n];
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            cols[i] = x;
        }
        int i=0;
        for(; i<n-1; ++i){
            m += cols[i];
            cols[i] = 0;
            int diff = cols[i+1] - cols[i];
            if(diff > k){
                if(m < diff - k)
                    break;
                else
                    m -= diff - k;
            }
        }
        if(i==n-1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
