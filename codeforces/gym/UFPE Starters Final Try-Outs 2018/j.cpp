#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/tree/heap.hpp>

vii prop;

bool cmp_max(ii &i, ii &j){
    int bi = prop[i.ss].ff, bj = prop[j.ss].ff;
    if(bi < bj)
        return true;
    else if(bi == bj)
        return i.ff >= j.ff;
    else
        return false;
}

bool cmp_min(ii &i, ii &j){
    return tie(prop[i.ss].ss, i.ff) <= tie(prop[j.ss].ss, j.ff);
}

bool solve(vi arr, int k, int m){
    vii max_s, min_s;
    for(int i=0; i<arr.size(); ++i){
        max_s.pb({arr[i], i});
        min_s.pb({arr[i], i});
    }
    sort(max_s.begin(), max_s.end(), cmp_max);
    sort(min_s.begin(), min_s.end(), cmp_min);

    int i=0, j=0;
    while(i < max_s.size() and j < min_s.size()){
        int si = max_s[i].ss, sj = min_s[j].ss;

        if(arr[si] <= m){
            i++;
            continue;
        }
        if(arr[sj] >= m){
            j++;
            continue;
        }

        int times = min(arr[si]-m, m-arr[sj]);
        arr[si] -= times;
        arr[sj] += times;
        k -= times*(prop[si].ff+prop[sj].ss);

        if(k < 0)
            return false;
    }

    for(int i:arr){
        if(i > m)
            return false;
    }

    return true;
}

int32_t main(){
    desync();
    int n, k;
    cin >> n >> k;

    vi arr;
    for(int i=0; i<n; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        arr.pb(a);
        prop.pb({b, c});
    }

    int lo = 0, hi = 1e6, ans = 1e6;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(solve(arr, k, mid)){
            ans = min(mid, ans);
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    cout << ans << endl;
    return 0;
}
