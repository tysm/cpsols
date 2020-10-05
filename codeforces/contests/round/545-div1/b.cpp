#include <cpplib/stdinc.hpp>
#include <cpplib/string/pi-function.hpp>

int32_t main(){
    desync();
    string s, t;
    cin >> s >> t;
    int s1 = 0;
    for(char c:s)
        s1 += (c == '1');
    int s0 = s.size()-s1;

    vi tpi = prefix_function(t);

    vi pt(all(t));
    for(int i=0; i<t.size(); ++i){
        pt[i] -= '0';
        if(i)
            pt[i] += pt[i-1];
    }

    int t1 = pt[t.size()-1], t0 = t.size()-t1;
    if(s1 >= t1 and s0 >= t0){
        s1 -= t1;
        s0 -= t0;
        cout << t;
        int r = t.size()-1, l = tpi[r];
        t = t.substr(l, r-l+1);
        t1 = pt[r] - (l? pt[l-1] : 0);
        t0 = r-l+1-t1;
    }
    while(s1 >= t1 and s0 >= t0){
        s1 -= t1;
        s0 -= t0;
        cout << t;
    }
    for(; s1; --s1)
        cout << 1;
    for(; s0; --s0)
        cout << 0;
    cout << endl;
    return 0;
}
