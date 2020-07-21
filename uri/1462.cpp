#include <cpplib/stdinc.hpp>
#include <cpplib/graph/erdos-gallai.hpp>

int32_t main(){
    int n;
    while(scanf("%li", &n) == 1){
        vi v(n);
        for(int &i:v)
            scanf("%li", &i);
        printf("%s\n", (erdos(v)? "possivel" : "impossivel"));
    }
    return 0;
}
