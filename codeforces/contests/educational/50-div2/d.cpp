#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;
    vi arr(n);
    for(int &i:arr)
        cin >> i;
    int m;
    cin >> m;
    vi brr(m);
    for(int &i:brr)
        cin >> i;

    int ar=1, br=1, acc = arr[0], bcc = brr[0], ans = 0;
    while(ar < n and br < m){
        if(acc == bcc){
            ans++;
            acc = arr[ar++];
            bcc = brr[br++];
        }
        else if(acc < bcc)
            acc += arr[ar++];
        else
            bcc += brr[br++];
    }
    while(ar < n)
        acc += arr[ar++];
    while(br < m)
        bcc += brr[br++];
    cout << (acc == bcc? ans+1 : -1) << endl;
    return 0;
}
