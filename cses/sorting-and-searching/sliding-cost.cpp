#include <cpplib/stdinc.hpp>

int ninc, ndec;
multiset<int> h1, h2;

int h1_value(){
    return -(*h1.begin());
}

int h2_value(){
    return *h2.begin();
}

void insert_h1(int value){
    if(h1.size() > 0){
        if(value > h1_value())
            ninc += h1.size()*(value - h1_value());
        else
            ninc += h1_value() - value;
    }
    h1.insert(-value);
}

void insert_h2(int value){
    if(h2.size() > 0){
        if(value > h2_value())
            ndec += value - h2_value();
        else
            ndec += h2.size()*(h2_value() - value);
    }
    h2.insert(value);
}

void remove_h1(int value){
    h1.erase(h1.lower_bound(-value));
    if(h1.size() > 0){
        if(value > h1_value())
            ninc -= h1.size()*(value - h1_value());
        else
            ninc -= h1_value() - value;
    }
}

void remove_h2(int value){
    h2.erase(h2.lower_bound(value));
    if(h2.size() > 0){
        if(value > h2_value())
            ndec -= value - h2_value();
        else
            ndec -= h2.size()*(h2_value() - value);
    }
}

void balance(){
    while(h2.size() > h1.size()){
        insert_h1(h2_value());
        remove_h2(h2_value());
    }
    int k = h1.size() + h2.size();
    while(h1.size() > h2.size() + (k%2)){
        insert_h2(h1_value());
        remove_h1(h1_value());
    }
}

void insert(int value){
    if(h1.size() == 0 or value <= h1_value())
        insert_h1(value);
    else
        insert_h2(value);
    balance();
}

void remove(int value){
    if(value <= h1_value())
        remove_h1(value);
    else
        remove_h2(value);
    balance();
}

int median(){
    return h1_value();
}

int cost(){
    if(h2.size() > 0)
        return ninc + (median() - h1_value())*h1.size() + ndec + (h2_value() - median())*h2.size();
    assert(ninc == 0 and ndec == 0);
    return 0;
}

int32_t main(){
    // https://cses.fi/problemset/task/1077
    desync();
    int n, k;
    cin >> n >> k;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    for(int i=0; i<k; ++i)
        insert(arr[i]);

    cout << cost();
    for(int i=k; i<n; ++i){
        remove(arr[i-k]);
        insert(arr[i]);
        cout << ' ' << cost();
    }
    cout << endl;
    return 0;
}
