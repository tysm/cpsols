#include <cpplib/stdinc.hpp>
#include <cpplib/adt/heap.hpp>

int32_t main(){
    desync();
    int n;
    while(cin >> n){
        int sum = 0;
        vvi arr(n, vi(n));
        for(vi &v:arr){
            for(int &i:v)
                cin >> i;
            sort(all(v));
            sum += v[0];
        }

        min_heap<pair<int, vi> > pq;
        pq.ep(sum, vi(n));

        set<vi> seen;
        seen.ep(vi(n));

        vi ans;
        while(ans.size() < n){
            int v = pq.top().ff;
            vi seed = pq.top().ss;
            pq.pop();

            if(seen.count(seed))
                continue;
            seen.ep(seed);

            ans.eb(v);

            for(int i=0; i<n; ++i){
                v -= arr[i][seed[i]];
                seed[i] += 1;
                if(seed[i] < n){
                    v += arr[i][seed[i]];
                    pq.ep(v, seed);
                    v -= arr[i][seed[i]];
                }
                seed[i] -= 1;
                v += arr[i][seed[i]];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
