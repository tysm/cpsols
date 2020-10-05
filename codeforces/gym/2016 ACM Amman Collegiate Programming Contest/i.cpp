#include <cpplib/stdinc.hpp>

int r, c;
string s;

int checkc(int cur){
    int res = 0;
    for(char x:s){
        if(x == '^' or x == 'v')
            continue;
        if(x == '>'){
            if(cur == c)
                res++;
            else
                cur++;
        }
        if(x == '<'){
            if(cur == 1)
                res++;
            else
                cur--;
        }
    }
    return res;
}

int checkr(int cur){
    int res = 0;
    for(char x:s){
        if(x == '>' or x == '<')
            continue;
        if(x == '^'){
            if(cur == r)
                res++;
            else
                cur++;
        }
        if(x == 'v'){
            if(cur == 1)
                res++;
            else
                cur--;
        }
    }
    return res;
}

int32_t main(){
    desync();
    int t;
    cin >> t;
    while(t--){
        cin >> r >> c;
        cin >> s;

        int ans = 0;
        {
        int lor = 1, hir = r;
        while(hir-lor > 2){
            int m1 = lor + (hir-lor)/3, m2 = hir - (hir-lor)/3;
            if(checkr(m1) > checkr(m2))
                lor = m1;
            else
                hir = m2;
        }
        int ansr = checkr(lor);
        for(int i=lor+1; i<=hir; ++i)
            ansr = min(ansr, checkr(i));
        ans += ansr;
        }

        {
        int loc = 1, hic = c;
        while(hic - loc > 2){
            int m1 = loc + (hic-loc)/3, m2 = hic - (hic-loc)/3;
            if(checkc(m1) > checkc(m2))
                loc = m1;
            else
                hic = m2;
        }
        int ansc = checkc(loc);
        for(int i=loc+1; i<=hic; ++i)
            ansc = min(ansc, checkc(i));
        ans += ansc;
        }

        cout << ans << endl;
    }
    return 0;
}
