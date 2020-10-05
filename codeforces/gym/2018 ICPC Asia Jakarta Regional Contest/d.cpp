#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int r, c;
    cin >> r >> c;

    vector<string> arr(r);
    for(string &s:arr)
        cin >> s;

    int ans = 0;
    if(r == 1 or c == 1){
        if(r > 2 or c > 2){
            string s;
            if(c == 1){
                for(int i=0; i<r; ++i)
                    s += arr[i][0];
                swap(r, c);
            }
            else
                s = arr[0];
            for(int i=1; i<c-1; ++i)
                ans += (s[i] == '.');
        }
    }
    else if(r == 2 or c == 2){
        if(r > 2 or c > 2){
            string s;
            if(r == 2){
                for(int j=0; j<c; ++j){
                    if(arr[0][j] == '.' and arr[1][j] == '.')
                        s += '.';
                    else
                        s += '#';
                }
            }
            else{
                for(int i=0; i<r; ++i){
                    if(arr[i][0] == '.' and arr[i][1] == '.')
                        s += '.';
                    else
                        s += '#';
                }
            }
            int n = s.size();
            for(int i=1; i<n-1; ++i)
                ans += (s[i] == '.');
        }
    }
    else{
        for(int i=1; i<r-1; ++i){
            for(int j=1; j<c-1; ++j){
                if(arr[i][j] == '.')
                    ans++;
            }
        }

        bool ok = false;
        for(int j=1; j<c-1; ++j){
            if(arr[0][j] == '#' or arr[r-1][j] == '#')
                ok = true;
        }
        for(int i=1; i<r-1; ++i){
            if(arr[i][0] == '#' or arr[i][c-1] == '#')
                ok = true;
        }
        if(!ok)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
