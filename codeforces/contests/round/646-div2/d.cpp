#include <cpplib/stdinc.hpp>

int query(vi &q){
    cout << "? " << q.size();
    for(int i:q)
        cout << ' ' << i;
    cout << endl;
    cout.flush();

    int x;
    cin >> x;
    return x;
}

int query(int n){
    vi q(n);
    iota(q.begin(), q.end(), 1);
    return query(q);
}

int query(int n, vi &v){
    vi cnt(n+1), q;
    for(int i:v)
        cnt[i]++;
    for(int i=1; i<=n; ++i){
        if(cnt[i])
            continue;
        q.pb(i);
    }
    return query(q);
}

void output(vi &ans){
    cout << '!';
    for(int i:ans)
        cout << ' ' << i;
    cout << endl;
    cout.flush();

    string trash;
    cin >> trash;
}

void solve(){
    int n, k;
    cin >> n >> k;

    vvi sets(k);
    for(vi &si:sets){
        int sz;
        cin >> sz;
        si.resize(sz);
        for(int &i:si)
            cin >> i;
    }

    int low = 0, high = k-1, maxv = query(n);
    while(low < high){
        int mid = (low+high)/2;

        vi q;
        for(int i=low; i<=mid; ++i){
            for(int j:sets[i])
                q.pb(j);
        }

        if(query(q) == maxv)
            high = mid;
        else
            low = mid+1;
    }

    vi ans(k);
    for(int i=0; i<k; ++i)
        ans[i] = (low == i? query(n, sets[i]) : maxv);
    output(ans);
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
