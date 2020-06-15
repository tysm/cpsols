#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int a, k;
        cin >> a >> k;
        for(int i=1; i<k; ++i){
            string si = to_string(a);
            int maxd = *max_element(all(si)) - '0', mind = *min_element(all(si)) - '0';
            if(mind == 0)
                break;
            a += mind*maxd;
        }
        cout << a << endl;
    }
    return 0;
}
