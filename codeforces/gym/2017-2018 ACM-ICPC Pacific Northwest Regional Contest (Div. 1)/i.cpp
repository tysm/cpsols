#include <cpplib/stdinc.hpp>

void canon(vector<tuple<char, int, char> > &prog){
    int n = prog.size();
    for(int r=0; r<n; ++r){
        for(int i=1; i<n; ++i){
            auto &[x1, y1, z1] = prog[i-1];
            auto &[x2, y2, z2] = prog[i];
            if(x1 == x2){
                if(x1 == 'I'){ // Ins(x) Ins(y)
                    if(y2 > y1) // Ins(x) Ins(x+z) z > 0
                        continue;
                    // Ins(x+z) Ins(x) z >= 0
                    y1++;
                    swap(prog[i], prog[i-1]);
                }
                else{ // Del(x) Del(y)
                    if(y1 > y2) // Del(x+z) Del(x) z > 0
                        continue;
                    // Del(x) Del(x+z) z >= 0
                    y2++;
                    swap(prog[i], prog[i-1]);
                }
            }
            else{
                if(x1 == 'D') // Del(x) Ins(y)
                    continue;
                // Ins(x) Del(y) -> Del deve vir antes, se possível.
                if(y1 == y2){ // we can delete them.
                    prog.erase(prog.begin()+i-1, prog.begin()+i+1);
                    n -= 2;
                }
                else{
                    if(y1 > y2)
                        y1--;
                    else
                        y2--;
                    swap(prog[i], prog[i-1]);
                }
            }
        }
    }
}

int32_t main(){
    desync();
    vector<tuple<char, int, char> > prog1, prog2;
    char c;
    while(cin >> c, c != 'E'){
        int x;
        cin >> x;
        if(c == 'D')
            prog1.eb(c, x, '\0');
        else{
            char a;
            cin >> a;
            prog1.eb(c, x, a);
        }
    }
    while(cin >> c, c != 'E'){
        int x;
        cin >> x;
        if(c == 'D')
            prog2.eb(c, x, '\0');
        else{
            char a;
            cin >> a;
            prog2.eb(c, x, a);
        }
    }
    canon(prog1);
    canon(prog2);
    cout << (prog1 == prog2? 0 : 1) << endl;
    return 0;
}
