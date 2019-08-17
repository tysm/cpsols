#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> sticks;
        int stick_count[10001] = {};
        for(int i=0; i<4*n; ++i){
            int stick;
            cin >> stick;
            stick_count[stick]++;
            if(stick_count[stick]%2 == 0)
                sticks.push_back(stick);
        }
        if(sticks.size() / 2 != n){
            cout << "NO" << endl;
            continue;
        }
        sort(sticks.begin(), sticks.end());
        int area = sticks[0]*sticks[2*n-1];
        bool valid = true;
        for(int i=1; i<n; ++i){
            if(sticks[i]*sticks[2*n-1-i]!=area)
                valid=false;
        }
        if(valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
