#include <cpplib/stdinc.hpp>
#include <cpplib/data-structure/geoinc.hpp>

int32_t main(){
    desync();
    string s;
    cin >> s;
    int acc = 1, x = 0, y = 0;
    char l = 'A';
    vii ans;
    map<ii, int> cnt;
    for(char c:s){
        if(c == 'U'){
            y += acc;
            if(l != 'D'){
                ans.eb(x, y+1);
                acc *= 2;
                ans.eb(x, y-(acc+1));
            }
        }
        else if(c == 'D'){
            y -= acc;
            if(l != 'U'){
                ans.eb(x, y-1);
                acc *= 2;
                ans.eb(x, y+acc+1);
            }
        }
        else if(c == 'R'){
            x += acc;
            if(l != 'L'){
                ans.eb(x+1, y);
                acc *= 2;
                ans.eb(x-(acc+1), y);
            }
        }
        else{
            x -= acc;
            if(l != 'R'){
                ans.eb(x-1, y);
                acc *= 2;
                ans.eb(x+acc+1, y);
            }
        }
        l = c;
        cnt[ii(x, y)]++;
    }
    if(cnt[ii(x, y)] > 1){
        cout << "impossible" << endl;
        return 0;
    }
    cout << -x << ' ' << -y << endl;
    cout << ans.size() << endl;
    for(ii i:ans)
        cout << i.ff - x << ' ' << i.ss - y << endl;
    return 0;
}
