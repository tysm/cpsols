#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    bool ok = true;
    int acc = 0, aux = -1;
    map<int, int> cnt;

    vi arr(n);
    for(int &i:arr){
        cin >> i;
        cnt[i]++;
        if(cnt[i] >= 2){
            acc++;
            aux = i;
            if(cnt[i] > 2 or acc >= 2 or i == 0)
                ok = false;
        }
    }
    sort(all(arr));

    if(*max_element(all(arr)) == 0 or !ok){
        cout << "cslnb" << endl;
        return 0;
    }

    if(acc and cnt[aux-1]){
        cout << "cslnb" << endl;
        return 0;
    }
    int ops = arr[0];
    arr[0] = 0;
    for(int i=1; i<n; ++i){
        ops += arr[i]-(arr[i-1]+1);
        arr[i] = arr[i-1]+1;
    }
    cout << (ops%2? "sjfnb" : "cslnb") << endl;
    return 0;
}
