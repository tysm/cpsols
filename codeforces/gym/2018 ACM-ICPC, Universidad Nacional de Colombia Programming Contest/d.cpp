#include <cpplib/stdinc.hpp>
#include <cpplib/adt/point.hpp>
#include <cpplib/geo/sort.hpp>
#include <cpplib/geo/see.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vector<point<double> > arr(n);
    for(int i=0; i<n; ++i)
        cin >> arr[i].x >> arr[i].y;
    auto mid = get<0>(see(arr, 3000));

    map<point<double>, int> pos;
    for(int i=0; i<n; ++i)
        pos[arr[i]] = i;

    polar_sort(arr, mid);

    vi conv(n);
    for(int i=0; i<n; ++i)
        conv[pos[arr[i]]] = i;

    vector<point<double> > res(n);
    for(int i=0, j=1; i<n; ++i, j=(j+1)%n){
        res[i] = arr[i]^arr[j];
        if(i)
            res[i] += res[i-1];
    }

    point<double> ans;
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        u = conv[u-1];
        v = conv[v-1];
        if(u > v)
            swap(u, v);

        point<double> cur = res[v-1] + (arr[v]^arr[u]);
        if(u)
            cur -= res[u-1];
        point<double> op = res[n-1] - cur;
        if(squared_norm(op) > squared_norm(cur)){
            if(squared_norm(ans) < squared_norm(cur))
                ans = cur;
        }
        else{
            if(squared_norm(ans) < squared_norm(op))
                ans = op;
        }
    }
    cout << fixed << setprecision(16) << norm(point<double>(ans)/2) << endl;
    return 0;
}
