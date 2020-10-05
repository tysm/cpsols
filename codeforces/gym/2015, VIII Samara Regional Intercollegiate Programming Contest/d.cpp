#include <cpplib/stdinc.hpp>

int32_t main(){
    desync();
    int n;
    cin >> n;

    if(n <= 2){
        cout << "FAIL" << endl;
        return 0;
    }

    vvi ans(3);
    if(n%2){
        ans[0] = {1, 6, 8};
        ans[1] = {2, 4, 9};
        ans[2] = {3, 5, 7};
    }
    else{
        ans[0] = {1, 3, 10, 12};
        ans[1] = {2, 7, 8, 9};
        ans[2] = {4, 5, 6, 11};
    }

    for(int i=3*(n%2? 3 : 4)+1; i<3*n+1; i+=6){
        ans[0].eb(i);
        ans[1].eb(i+1);
        ans[2].eb(i+2);
        ans[2].eb(i+3);
        ans[1].eb(i+4);
        ans[0].eb(i+5);
    }

    cout << "WIN" << endl;
    for(int i=0; i<3; ++i)
        cout << ans[i] << endl;
    return 0;
}
