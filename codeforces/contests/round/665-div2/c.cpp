#include <cpplib/stdinc.hpp>
#include <cpplib/adt/heap.hpp>

bool check(vi &arr){
    for(int i=1; i<arr.size(); ++i){
        if(arr[i] < arr[i-1])
            return false;
    }
    return true;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mval = LINF;
        vi arr(n);
        for(int &i:arr){
            cin >> i;
            mval = min(i, mval);
        }
        min_heap<int> pq;
        for(int i:arr){
            if(i%mval == 0)
                pq.ep(i);
        }
        vi cur(n);
        for(int i=0; i<n; ++i){
            if(arr[i]%mval == 0){
                cur[i] = pq.top();
                pq.pop();
            }
            else
                cur[i] = arr[i];
        }
        cout << (check(cur)? "YES" : "NO") << endl;
    }
    return 0;
}
