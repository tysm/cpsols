#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    int cnt2 = 0, cnt4 = 0;
    vi cnt(1e5+1);
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        cnt[x]++;
        if(cnt[x]%4 == 0){
            cnt4++;
            cnt2--;
        }
        else if(cnt[x]%2 == 0)
            cnt2++;
    }
    int q;
    cin >> q;
    while(q--){
        char op;
        int x;
        cin >> op >> x;
        if(op == '+'){
            cnt[x]++;
            if(cnt[x]%4 == 0){
                cnt4++;
                cnt2--;
            }
            else if(cnt[x]%2 == 0)
                cnt2++;
        }
        else{
            if(cnt[x]%4 == 0){
                cnt4--;
                cnt2++;
            }
            else if(cnt[x]%2 == 0)
                cnt2--;
            cnt[x]--;
        }
        if(cnt4 >= 2 or cnt4 >= 1 and cnt2 >= 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
