#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi arr(n);
        for(int &i:arr)
            cin >> i;
        sort(all(arr));
        bool valid = false;
        for(int k=1; k<=1024 and !valid; ++k){
            vi aux;
            for(int i:arr)
                aux.pb(i^k);
            sort(all(aux));
            bool found = true;
            for(int i=0; i<n and found; ++i){
                if(aux[i] != arr[i])
                    found = false;
            }
            if(found){
                cout << k << endl;
                valid = true;
            }
        }
        if(!valid)
            cout << -1 << endl;
    }
    return 0;
}
