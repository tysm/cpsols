#include <cpplib/stdinc.hpp>
#include <cpplib/adt/matrix.hpp>

bool inside(int i, int j){
    if(i < 0 or i >= 8)
        return false;
    if(j < 0 or j >= 8)
        return false;
    return true;
}

int32_t main(){
    desync();
    int k;
    cin >> k;
    matrix<uint32_t, 65> one(0);
    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            for(int di:{-2, -1, 1, 2}){
                for(int dj:{-2, -1, 1, 2}){
                    if(abs(di) == abs(dj))
                        continue;
                    if(!inside(i+di, j+dj))
                        continue;
                    one[8*i+j][8*(i+di)+(j+dj)] = 1;
                }
            }
        }
    }
    for(int i=0; i<65; ++i)
        one[i][64] = 1;
    cout << exp(one, k+1)[0][64] << endl;
    return 0;
}
