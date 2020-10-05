#include <cpplib/stdinc.hpp>

vi AUX(3e5+1);

int inv_sort(vi &v, int l, int r){
    if(l == r) // already sorted -> no inversions.
        return 0;

    int res = 0, mid = (l+r)/2;
    res += inv_sort(v, l, mid) + inv_sort(v, mid+1, r);

    for(int i=l; i<=mid; ++i)
        AUX[i] = v[i];
    for(int i=mid+1; i<=r; ++i)
        AUX[i] = v[i];

    int i = l, j = mid+1;
    for(int k=l; k<=r; ++k){
        if(i <= mid and j <= r){
            if(AUX[i] <= AUX[j])
                v[k] = AUX[i++];
            else{
                v[k] = AUX[j++];
                res += mid-i+1;
            }
        }
        else if(i <= mid)
            v[k] = AUX[i++];
        else
            v[k] = AUX[j++];
    }
    return res;
}

int32_t main(){
    desync();
    int n;
    cin >> n;

    vi arr(n);
    for(int &i:arr)
        cin >> i;

    vi aux(arr);
    int b = inv_sort(aux, 0, n-1), x = 0;
    for(int k=0; k<=29; ++k){
        int xi = x^(1<<k);
        for(int i=0; i<n; ++i)
            aux[i] = arr[i]^xi;
        int bi = inv_sort(aux, 0, n-1);
        if(bi < b){
            x = xi;
            b = bi;
        }
    }
    cout << b << ' ' << x << endl;
    return 0;
}
