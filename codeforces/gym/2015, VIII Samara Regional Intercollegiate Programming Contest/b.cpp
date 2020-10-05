#include <cpplib/stdinc.hpp>

int row(int x, int p){
    return (x-1)%p;
}

int col(int x, int p){
    return (x-1)/p;
}

int32_t main(){
    desync();
    int p, n, x;
    cin >> p >> n >> x;

    int c = col(x+1, p), cn = col(n+1, p);
    int r = row(x+1, p), rn = row(n+1, p);
    int ans1 = cn + 1 + abs(rn - r) + cn - c, ans;
    if(c == cn)
        ans = c+r; // right + down.
    else
        ans = x/p + min(x%p, 1+p-x%p); // right + (down vs right + up).
    cout << min(ans, ans1) << endl;
    return 0;
}
