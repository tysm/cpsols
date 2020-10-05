#include <cpplib/stdinc.hpp>

int mod(int i, int n){
    return (i%n + n)%n;
}

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vvi pos(m+1);

    vi arr(n);
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        pos[arr[i]].eb(i);
    }

    set<ii> itv1, itv2;
    vii itv(n, ii(-1, -1));
    for(int i=1; i<=m; ++i){
        if(pos[i].empty()){
            cout << -1 << endl;
            continue;
        }
        int ans = n-pos[i].size();

        for(int j=0; j<pos[i].size()){
            auto it = itv2.lower_bound(ii(n-1-i));
            if(it != itv2.end()){
                if(it->ff 
            }
        }

        cout << ans << endl;
        for(int i:pos[i]){
            ii l = itv[mod(i-1, n)], r = itv[mod(i+1, n)];
            itv1.erase(l);
            itv2.erase(ii(n-l.ss, n-l.ff));

            if(l == ii(-1, -1))
                l = ii(i, i);
            if(r == ii(-1, -1))
                r = ii(i, i);

            itv1.erase(r);
            itv2.erase(ii(n-r.ss, n-r.ff));

            ii res = ii(l.ff, r.ss);

            itv[res.ff] = res;
            itv[res.ss] = res;
            itv1.ep(res);
            itv2.ep(ii(n-res.ss, n-res.ff));
        }
    }
    return 0;
}
