#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n, m;
    cin >> n >> m;

    vvi arr(n, vi(m));
    for(vi &v:arr){
        for(int &i:v)
            cin >> i;
    }

    for(int b=0; (1<<b) <= 1023; ++b){
        int x = 0, y = 0, z = 0;
        for(int i=0; i<n; ++i){
            int k = false, l = false;
            for(int j=0; j<m; ++j){
                if((1<<b) & arr[i][j])
                    k = true;
                else
                    l = true;
            }
            x += k;
            y += l;
            z += (k and l);
        }
        if(!x or x+y-z < n or x%2 == 0 and z == 0)
            continue;
        if(x%2 == 0){
            x--;
            z--;
        }
        cout << "TAK" << endl;
        vi out;
        for(int i=0; i<n; ++i){
            int k = 0, l = 0;
            for(int j=0; j<m; ++j){
                if(arr[i][j] & (1<<b))
                    k = j+1;
                else
                    l = j+1;
            }
            if(k and l){
                if(z){
                    x--;
                    z--;
                    out.eb(k);
                }
                else
                    out.eb(l);
                y--;
            }
            else if(k){
                out.eb(k);
                x--;
            }
            else{
                out.eb(l);
                y--;
            }
        }
        cout << out << endl;
        return 0;
    }
    cout << "NIE" << endl;
    return 0;
}
