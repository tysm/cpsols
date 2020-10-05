#include <cpplib/stdinc.hpp>
#include <cpplib/math/number-theory/prime-number/gries-misra.hpp>

Sieve sv(5e5);

int acc, ans;
vi cnt(5e5+1);
vb has(2e5+1);

void add(int x){
    acc++;
    auto f = sv.factorization(x);
    for(int b=1; b < (1 << f.size()); ++b){
        int prod = 1;
        for(int i=0; i<f.size(); ++i){
            if(b & (1 << i))
                prod *= f[i].ff;
        }
        if(__builtin_popcount(b) & 1)
            ans += cnt[prod];
        else
            ans -= cnt[prod];
        cnt[prod]++;
    }
}

void rem(int x){
    acc--;
    auto f = sv.factorization(x);
    for(int b=1; b < (1 << f.size()); ++b){
        int prod = 1;
        for(int i=0; i<f.size(); ++i){
            if(b & (1 << i))
                prod *= f[i].ff;
        }
        cnt[prod]--;
        if(__builtin_popcount(b) & 1)
            ans -= cnt[prod];
        else
            ans += cnt[prod];
    }
}

int32_t main(){
    desync();
    int n, q;
    cin >> n >> q;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    while(q--){
        int x;
        cin >> x;
        x--;
        if(has[x])
            rem(arr[x]);
        else
            add(arr[x]);
        has[x] = !has[x];
        cout << acc*(acc - 1)/2 - ans << endl;
    }
    return 0;
}
