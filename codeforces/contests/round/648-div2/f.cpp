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
        vi res(n);
        for(int &i:res)
            cin >> i;

        map<ii, int > cnt;
        int mid = (n-1)/2;
        for(int i=0; i<=mid; ++i){
            ii aux = {arr[i], arr[n-i-1]};
            if(aux.ss < aux.ff)
                swap(aux.ss, aux.ff);
            cnt[aux]++;
            aux = {res[i], res[n-i-1]};
            if(aux.ss < aux.ff)
                swap(aux.ss, aux.ff);
            cnt[aux]--;
        }
        bool valid = true;
        for(pair<ii, int> i:cnt){
            if(i.ss != 0)
                valid = false;
        }
        if(valid)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
