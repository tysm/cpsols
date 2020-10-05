#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;

        vi arr(n);
        for(int &i:arr)
            cin >> i;

        set<int> pos, neg;
        pos.ep(0);
        neg.ep(0);
        for(int i=n-1; i>=0; --i){
            int pi = arr[i] - (*neg.begin());
            int ni = -arr[i] - (*pos.begin());
            pos.ep(-pi);
            neg.ep(-ni);
        }

        cout << -(*pos.begin()) << endl;
    }
    return 0;
}
