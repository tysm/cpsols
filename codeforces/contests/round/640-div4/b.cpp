#include <cpplib/stdinc.hpp>

vi solve(int n, int k){
    int r1 = n - (k-1), r2 = n - (k-1)*2;
    if(r1 > 0 and r1%2){
        vi res(k-1, 1);
        res.pb(r1);
        return res;
    }
    else if(r2 > 0 and r2%2 == 0){
        vi res(k-1, 2);
        res.pb(r2);
        return res;
    }
    return vi();
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi ans = solve(n, k);
        if(ans.size() != 0){
            cout << "YES" << endl;
            for(int i=0; i<ans.size(); ++i){
                if(i)
                    cout << ' ';
                cout << ans[i];
            }
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
