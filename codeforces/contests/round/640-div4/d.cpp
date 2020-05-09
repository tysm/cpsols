#include <cpplib/stdinc.hpp>

int32_t main(){
    // desync();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vi arr(n);
        for(int &i:arr)
            cin >> i;

        int i = 0, j = n-1, a = 0, b = 0, acc = 0, m = 0;
        while(i <= j){
            int p = m%2, aux = 0;
            while(i <= j and aux <= acc){
                if(p == 0){
                    aux += arr[i];
                    i++;
                }
                else{
                    aux += arr[j];
                    j--;
                }
            }
            if(p == 0)
                a += aux;
            else
                b += aux;
            acc = aux;
            m += 1;
        }
        cout << m << ' ' << a << ' ' << b << endl;
    }
    return 0;
}
