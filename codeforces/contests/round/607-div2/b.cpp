#include <cpplib/stdinc.hpp>
#include <cpplib/adt/heap.hpp>

string solve(string &a, string &b){
    int n = a.size();

    min_heap<pair<char, int> > pq;
    for(int i=1; i<n; ++i)
        pq.emplace(a[i], -i);

    for(int i=0; i<n-1; ++i){
        while(-pq.top().ss <= i)
            pq.pop();
        int j = -pq.top().ss;
        if(a[j] < a[i]){
            swap(a[i], a[j]);
            break;
        }
    }
    return a < b? a : "---";
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}
