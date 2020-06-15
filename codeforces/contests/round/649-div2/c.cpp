#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/order-statistic-tree.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    set<int> mex;
    for(int i=0; i<=1e6; ++i)
        mex.insert(i);

    vi arr(n), cnt(1e6+1);
    for(int &i:arr){
        cin >> i;
        mex.erase(i);
        cnt[i]++;
    }
    for(int i=0; i<n; ++i){
        int aux = *mex.begin();
        if(i)
            cout << ' ';
        cout << aux;

        cnt[aux]++;
        mex.erase(mex.begin());

        cnt[arr[i]]--;
        if(!cnt[arr[i]])
            mex.insert(arr[i]);
    }
    cout << endl;
    return 0;
}
