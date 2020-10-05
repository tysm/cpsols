#include <cpplib/stdinc.hpp>

double calc(int a, int b){
    double p = 2*(a+b), s = a*b;
    return (p*p)/s;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        bool ok = false;
        map<int, int> cnt;
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            cnt[x]++;
            if(cnt[x] == 4 and !ok){
                for(int j=0; j<4; ++j)
                    cout << x << " \n"[j==3];
                ok = true;
            }
        }
        if(ok)
            continue;

        vi arr;
        for(ii i:cnt){
            if(i.ss >= 2)
                arr.eb(i.ff);
        }
        sort(all(arr));

        int ans = 0;
        double cur = calc(arr[0], arr[1]);
        for(int i=1; i+1<arr.size(); ++i){
            double res = calc(arr[i], arr[i+1]);
            if(res < cur){
                cur = res;
                ans = i;
            }
        }
        cout << arr[ans] << ' ' << arr[ans] << ' ' << arr[ans+1] << ' ' << arr[ans+1] << endl;
    }
    return 0;
}
