#include <cpplib/stdinc.hpp>

multiset<int> h1, h2;

void balance(){
    while(h2.size() > h1.size()){
        h1.insert(-(*h2.begin()));
        h2.erase(h2.begin());
    }
    int k = h1.size() + h2.size();
    while(h1.size() > h2.size() + (k%2)){
        h2.insert(-(*h1.begin()));
        h1.erase(h1.begin());
    }
}

void insert(int value){
    if(h1.empty() or value <= -(*h1.begin()))
        h1.insert(-value);
    else
        h2.insert(value);
    balance();
}

void remove(int value){
    if(value <= -(*h1.begin()))
        h1.erase(h1.lower_bound(-value));
    else
        h2.erase(h2.lower_bound(value));
    balance();
}

int32_t main(){
    // https://cses.fi/problemset/task/1076
    desync();
    int n, k;
    cin >> n >> k;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    for(int i=0; i<k; ++i)
        insert(arr[i]);

    cout << -(*h1.begin());
    for(int i=k; i<n; ++i){
        remove(arr[i-k]);
        insert(arr[i]);
        cout << ' ' << -(*h1.begin());
    }
    cout << endl;
    return 0;
}
