#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, l, r, k;
    cin >> n >> l >> r >> k;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    vi ans(1, 0);
    for(int i=1; i<n; ++i){
        if(arr[i] == arr[i-1])
            ans.eb(ans.back());
        else if(arr[i] > arr[i-1])
            ans.eb(ans.back()+1);
        else
            ans.eb(ans.back()-1);
    }
    debug(ans);

    int min_val = *min_element(all(ans)), d = l-min_val;
    for(int &i:ans)
        i += d;

    vi aux(ans);
    for(int i=n-2; i>=0; --i)
        aux[i] = min(aux[i], aux[i+1]);

    int acc = 0, ok = true;
    for(int i=0; i<n; ++i){
        ans[i] += acc;
        aux[i] += acc;
        if(ans[i] > r)
            ok = false;

        if(i){
            if(arr[i] >= arr[i-1])
                continue;
            int d = min(ans[i] - (ans[i-1]-k), aux[i]-l);
            ans[i] -= d;
            aux[i] -= d;
            acc -= d;
        }
    }

    if(!ok)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
