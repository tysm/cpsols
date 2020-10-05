#include <cpplib/stdinc.hpp>

int solve0(int n){
    if(n%6 < 3)
        return n%6;
    else
        return (n%6 == 5? 0 : (n%6 == 4? 1 : 2));
}

int solve1(int n){
    if(n <= 2)
        return 0;
    else
        return solve0(n-2);
}

int solve2(int n){
    if(n == 1)
        return 2;
    else if(n == 2)
        return 1;
    else
        return solve1(n-2);
}

int32_t main(){
    desync();
    int n, x;
    cin >> n >> x;
    if(solve0(n) == x)
        cout << 0 << endl;
    else if(solve1(n) == x)
        cout << 1 << endl;
    else
        cout << 2 << endl;
    return 0;
}
